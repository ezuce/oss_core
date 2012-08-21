// Library: OSS Software Solutions Application Programmer Interface
// Package: OSSABNF
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


#ifndef ABNF_SIPSIPTEXTUTF8CHAR_INCLUDED
#define ABNF_SIPSIPTEXTUTF8CHAR_INCLUDED


#include "OSS/ABNF/ABNFSIPRules.h"


namespace OSS {

namespace ABNF {


class OSS_API ABNFSIPTextUtf8Char : public ABNFBaseRule
  /// Satisfies RFC 3261 ABNF Rule for 
  /// TEXT-UTF8char   =  %x21-7E / UTF8-NONASCII
{
public:
  ABNFSIPTextUtf8Char();
  /// Creates a new ABNFSIPTextUtf8Char

  char* parse(const char* _t);
  /// Returns the next off-set if the rule is satisfied
};

typedef  ABNFSIPTextUtf8Char ABNF_SIP_TEXT_UTF8char;

} } //OSS::ABNF
#endif //ABNF_SIPSIPTEXTUTF8CHAR_INCLUDED