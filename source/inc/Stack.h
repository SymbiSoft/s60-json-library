/*
Copyright (c) 2009, Piotr Wach, Polidea
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Polidea nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY PIOTR WACH, POLIDEA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL PIOTR WACH, POLIDEA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef STACK_H
#define STACK_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>

// CLASS DECLARATION

/**
 *  CStack
 * 
 */
template< typename T > class RStack : public CBase
	{
public:
	// Constructors and destructor
	
	/**
	 * Constructor for performing 1st stage construction
	 */
	RStack()
		{
		// no implementation
		}
	
	void Close()
		{
		iStack.Close();
		}
	
	void PushL( const T& aEntry )
		{
		iStack.Append( aEntry );
		}
	
	void Pop()
		{
		if( iStack.Count() )
			iStack.Remove( iStack.Count() - 1 );		
		}
	
	T TopL()
		{
		if( !iStack.Count() )
			User::Leave( KErrUnderflow );
		return iStack[ iStack.Count() - 1 ];
		}
	
	TInt Count() const
		{
		return iStack.Count();
		}
	
	TBool IsEmpty() const 
		{
		return !Count();
		}

private:
	RArray< T > iStack;
	};

#endif // STACK_H
