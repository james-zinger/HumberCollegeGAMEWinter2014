///////////////////////////////////////////////////////////
//  BlackjackGame.h
//  Implementation of the Class BlackjackGame
//  Created on:      14-Mar-2014 5:29:06 PM
//  Original author: James
///////////////////////////////////////////////////////////

#pragma once

#include "Game.h"
#include "Deck.h"
#include "House.h"
#include "BlackjackPlayer.h"
#include "BlackjackProtocol.h"

#include <concurrent_vector.h>
#include <iostream>
#include <ctime>

using std::vector;
using std::cout;
using std::endl;
using std::ostream;
using std::time;
using Concurrency::concurrent_vector;

namespace Blackjack
{

	class BlackjackGame : public Game
	{
	public:
		BlackjackGame();

		virtual ~BlackjackGame();

		//plays the game of blackjack    
		void Play();



	private:
		Deck m_Deck;
		House m_House;

		concurrent_vector<BlackjackPlayer> m_Players;

	};
}
