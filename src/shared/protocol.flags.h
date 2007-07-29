/*******************************************************************************

   Copyright (C) 2006, 2007 M.K.A. <wyrmchild@users.sourceforge.net>

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   Except as contained in this notice, the name(s) of the above copyright
   holders shall not be used in advertising or otherwise to promote the sale,
   use or other dealings in this Software without prior written authorization.
   
   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.

---

   For more info, see: http://drawpile.sourceforge.net/

*******************************************************************************/

#ifndef Protocol_Flags_INCLUDED
#define Protocol_Flags_INCLUDED

namespace protocol
{

//! Client capabilities
/**
 * Protocol related client capabilities.
 */
namespace client
{

//! Client capabilities
enum capabilities
{
	//! No capabilities
	None,
	
	//! Ack feedback
	/**
	 * Client can operate with just ACKs as feedback from stroke info and chat messages.
	 * 
	 * Why? It lowers bandwidth! An ACK is only 2 bytes long compared to what the other
	 * messages are!
	 * 
	 * Without this, the messages get returned back to the client as if they were from
	 * some other user. Like boomerang, except you gain nothing.
	 */
	AckFeedback = 0x01
};

} // namespace client

//! Message modifiers
/**
 * http://drawpile.sourceforge.net/wiki/index.php/Protocol#Message_modifiers
 */
namespace message
{

//! Message modifiers
enum flags
{
	//! No message modifiers.
	None,
	
	//! Has user identifier
	isUser = 0x01,
	
	//! Has session identifier
	isSession = 0x02,
	
	//! Is bundling
	isBundling = 0x04,
	
	//! Is directed by SessionSelect message.
	isSelected = 0x08
};

} // namespace message

//! Protocol extension flags.
/**
 * @see protocol::Identifier message
 * @see protocol::HostInfo message
 * @see http://drawpile.sourceforge.net/wiki/index.php/Protocol#Extensions
 */
namespace extensions
{

//! Protocol extensions
enum flags
{
	//! No supported extensions.
	None,
	
	//! Chat extension
	Chat = 0x01u,
	
	//! Shared palette extension
	Palette = 0x02u,
	
	//! Deflate extension
	Deflate = 0x08u,
};

} // namespace extensions

//! Operation flags.
/**
 * @see protocol::HostInfo message
 */
namespace requirements
{

//! Server requirements
enum flags
{
	//! No special requirements.
	None,
	
	//! Enforces unique user and session names.
	EnforceUnique = 0x01u,
	
	//! Strings use UTF-16 format instead of default UTF-8.
	WideStrings = 0x08u,
	
	//! Server does not allow global Chat messages.
	NoGlobalChat = 0x10u,
	
	//! There's no central server
	Distributed = 0x40u
};

} // namespace requirements

//! User mode flags.
/**
 * Used in protocol::UserInfo and protocol::SessionInfo messages
 */
namespace user
{

//! User mode
enum mode
{
	//! Null user mode.
	None,
	
	//! User is identified as admin by the server
	/** Only applied to user */
	Administrator = 0x01u,
	
	//! User is not able to draw.
	Locked = 0x08u,
	
	//! User may not send Chat messages.
	Mute = 0x10u,
	
	//! User can't see Chat messages.
	Deaf = 0x20u
};

} // namespace user

//! Session flags
namespace session
{

//! Session flags
enum flags
{
	//! No flags set
	None,
	
	//! Session persists
	Persist = 0x01u
};

} // namespace session

} // namespace protocol

#endif // Protocol_Flags_INCLUDED
