Author: Michael Parker
Date: 3/11/2020
Version: 1.0

																			-DESIGN SECTION-
		
		Class structure & Brief Functionality: 
		
			RecordStore.cpp :
									void Menu() <--- bloated not on purpose but just short of time, would split everything up to clean up.
									void ChooseRecordFromJukeBox(int upc)
									void RecordFactory()

		    bailer.hpp: 
									Bailer(const size_t& table_size, const function<int(const string & key)>& hash_function) : lyrics_(table_size, hash_function) {}
									void Compress(const string& filename);
									void Decompress(const string& filename);
									void PrintLyrics();
									
									private variable: HashMap<string, vector<int>> lyrics_;
									

			record.hpp :				Record(int upc_, string title_) : upc(upc_), title(title_)
										void DisplayLyrics(int song)
										void AddSong(string lyrics)
										void PrintRecordInfo()


																	-THE DESIGN & THOUGHT PROCESS BEHIND THE PROGRAM-

										I wanted this to feel 'organic', which is why the sleep thread method is utilized throughout the program,
										like you were actually walking into a live record store so when text pops up 
									
															~~~~~~~~~~	PLEASE WAIT AT LEAST 4 seconds between commands. ~~~~~~~~~~

										The 'objects' the user interacts with acts and has functionality to their real life counter parts. 
										Also, I always ensure to build a way for the user to quit,
										I just have a little fun with my version of it :).
										
						
														  -GAME INSTRUCTION SECTION-
														~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


																 -CONTROLS-
		     c = Compress file. To get to the files just type the command this way: songs/[name of song file]. Only accepts .txt right now.
			 l = Show the compressed lyrics and their word number positions. 
			 d = Decompress the stored lyrics into a file. The command is: d_c_songs/[name of song file].txt
			 This should match original files formatting. 
			 r = Allows the user to create a record! Cool feature that stores a record into the stores juke box. 
			 j = Accesses the juke box! Say wahhhhhhhhhh?? A juke box?? Oh ya, a fully equipped one to only display a record number and title, but the user can still browse some sweet oldies :D.

														~~~~ Welcome to M-PAD Studios ~~~~
				You're goal...sell as many records as possible! Everytime a customer creates a record, compresses, and/or decompresses to store in the juke box we get cash money $$$ 
				As you know the past few years have been rough for sales so with the invention of the stores bailer/juke box combo we will easily be millionnnnnnaaaaaires. The goal $1,000,000!
				Why a million? Cause it is cliche movie script 101....enjoy :D.

													~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
