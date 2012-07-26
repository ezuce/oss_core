// Library: OSS Software Solutions Application Programmer Interface
// Package: OSSSIP
// Author: Joegen E. Baclor - mailto:joegen@ossapp.com
//
// Copyright (c) OSS Software Solutions
//
// Permission is hereby granted, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, execute, and to prepare 
// derivative works of the Software, all subject to the 
// "GNU Lesser General Public License (LGPL)".
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef SIP_SIPUDPListener_INCLUDED
#define SIP_SIPUDPListener_INCLUDED


#include <boost/asio.hpp>
#include <boost/noncopyable.hpp>
#include "OSS/SIP/SIPListener.h"
#include "OSS/SIP/SIPUDPConnection.h"
#include "OSS/STUN/STUNClient.h"
#include "OSS/STUN/STUNMappedAddress.h"

namespace OSS {
namespace SIP {

class SIPFSMDispatch;

class OSS_API SIPUDPListener: 
  public SIPListener,
  private boost::noncopyable
{
public:
  typedef boost::shared_ptr<SIPUDPListener> Ptr;
  
  SIPUDPListener(
    SIPTransportService* pTransportService,
    SIPFSMDispatch* dispatch,
    const std::string& address, 
    const std::string& port);
    /// Construct the server to listen on the specified TCP address and port.

  virtual ~SIPUDPListener();
    /// Destroys the server.

  virtual void run();
    /// Run the server's io_service loop.

  virtual void handleStop();
    /// Handle a request to stop the server.

  boost::asio::ip::udp::socket* _socket;
    /// Socket shared by all connections 

  SIPUDPConnection::Ptr connection();

  const OSS::STUN::STUNClient::Ptr& getStunClient();

  OSS::IPAddress detectNATBinding(const std::string& stunServer);

private:
  virtual void handleAccept(const boost::system::error_code& e);
    /// Handle completion of an asynchronous accept operation.

  virtual void connect(const std::string& address, const std::string& port);
    /// Connect to the specified address and port

  virtual void handleConnect(const boost::system::error_code& e, boost::asio::ip::tcp::resolver::iterator endPointIter);
    /// Handle completion of the connect operation.

  SIPUDPConnection::Ptr _pNewConnection;
    /// The next connection to be accepted.

  SIPFSMDispatch* _dispatch;
    /// The handler for all incoming requests.

  friend class SIPUDPConnection;

  OSS::STUN::STUNClient::Ptr _pStunClient;
  OSS::STUN::STUNMappedAddress _stunMappedAddress;
};

//
// Inlines
//

inline SIPUDPConnection::Ptr SIPUDPListener::connection()
{
  return _pNewConnection;
}

  /// Return the stun client shared pointer
inline const OSS::STUN::STUNClient::Ptr& SIPUDPListener::getStunClient()
{
  return _pStunClient;
}


} } // OSS::SIP
#endif // SIP_SIPUDPListener_INCLUDED

