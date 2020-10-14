Author: Michael Parker
Date: 2/28/2020
Version: 1.0

									-DESIGN SECTION-
		
		Class structure & Brief Functionality: 
		
			World.cpp :				void Menu()
									void CreateWorld()
									void RandomWorld()

		    game_board_manager.hpp: 
									
									GameBoardManager() = default;
									GameBoardManager(Board<char> board_)
									void DealBoards(Board<char> board_)
									void Timer(int ms)
									bool GameControls(char* c)
									

			board.hpp :				Array2D Board(int width, int height, int w_cell, int v_cell)
									void BoardWithBoarder()
									void DisplayBoard()
									int GraphNum()
									int WCell()
									int VCell()
									void NextState()
									void SwitchBoard(Board<char> board)
									void StoreBoardTxtFile(string file)
									void VirusOutBreak()

										-THE ALGORITH FOR THE PROGRAM RULES SECTION-
												Factorio Streamer Sweeper:

				I coined the algorithm I wrote for this based off a game one my best friends and I play called Factorio.
				You build massive automated factories and a techniuqe in the game used is to create these streamers of resources.
				If done correctly the streamers determine the entire flow of your production....that's what my algorithm does as well.
				Instead of reading the outlying neighbors it does it in a star burst formation. The algorithm is split into 2 parts.

				The first part lies within the BoardWithBoarder() method and does a random seed of each cell. The first time through the loop
				it will set the grid, then from there it will start to branch to the next conditional statements, initiating the streamers
				the streamers are crucial to the eb and flow of the game. They are created by using the Select() method from the Array2D class.
				If Select(random row chosen, static column) lands on either cell it will stream off from that cell, then cause another burst, then another, etc.
				This essentially will simulate "live movement" of cells. 
				
				A diagram is an easier way to picture this:

				R 0: C 0:C 1:C2
				R 1:         ?
				R 2:   ?????[v] ????????
				R 3:*****[w][c]******
				R 4:	  *******[w]**********
				R 5:	  *
				R 6:      *

				A collision is caused at R3 : C2 and would engage in the output being random when displayed to the user, which at times this appear as a stream of either '@' or '%'

				The second part of the algorithm is in NextState() method and it sends the current board through another factory sweeper but engaging the win/lose conditions of the board.
				During this stage, inside the factory sweeper the virus and white cells will do the correct swapping or 'fighting' of the CURRENT board. The board goes through final production 
				in the DisplayBoard() method, and spits out the correct CURRENT board.  A minor part to this algorithm which is almost like a, extra feature, is the VirusOutBreak() method. When triggered
				this will be simulated in real time to the user to show the virus cells are fighting back and winning! 
				
				I have built in one of the best ways to play the game. When simulating hit 'm' and it will shift the view of the board to dynamically update while not printing previous boards. This is
				achieved by 'tricking' the console system('cls') by putting a break point within the second while loop of the current games while loop. When threaded at a slow enough pace this is an 
				excellent way to study graphs. 

							  -GAME INSTRUCTION SECTION-
							~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		When you start the game for the first time hit 'w' then put in the dimensions below 
		with 7 x 13...you will notice the shifting of the white cells and virus cells...the pause is your hint
		that the virus cells are fighting back. 

		7 x 13 virus will win
		42 x 6 virus will win

		The count it asks for the white and virus cells when you first create just ignore...it does nothing atm
		but is needed for the world to be made. 

		During the simulation there are multiple different functions and view screens. There is a nice view I built in
		that I call the automatic manual mode. Start the program, hit r for quick world generation, then hit m when it starts running.
		This shifts the view to be static and not print multiple boards but allows the user to analyze graphs on the go.
		
		No matter what when it hits day
		1000 it is signifying that white blood cells will ineviatbly win and the simulation is over, saves your stats for the board to a txt file.

		This is your starting point...good luck :D

		  -CONTROLS-
		     p = pause
			 + = speed up graph time [NOT PROPERLY WORKING ATM]
			 s = you can save the graph if you press + wait for speed adjustment then hit s and it'll save
			 q = quit game

							~~~~ Welcome to The Game of Life ~~~~
				"Ahhhhh so you've made, excellent. Please sit down we have an urgent matter to discuss.""
							*general pulls up a hologram of the Earth*
				"Dr.Mikail Parkay, we need your assistance...the World depends on your research"
						*pushes up glasses and pulls out a circular disc* "oooooo-ho, 
						you see general I have already been conducting research..."

								~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

					You are Mikail Parkay a scientist that has created a super soldier...no no no not like those
				These white blood cells are enhanced...the circular disc Dr. Parkay has created is a dynamically growing petri dish
					It can either randomly generate simulations or you can enter in specific dimensions

		You're to study the graphs and analyze why certain dimensions cause stability for the super cells and why certain dimensions
										the virus cells win out.