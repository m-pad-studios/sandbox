import time
import sys

class WordSmith():

    name = input("Enter a name for the word smith to greet you by: ")

    def __init__(self, words, words_smithed):
        self.words = words
        self.words_smithed = words_smithed

    def reverse_things_then_join(self):
        wrd = input("Give me a word to reverse with a join please & thank you: ")
        mutated = ""
        mutated = mutated.join(reversed(wrd))
        print(mutated)

        self.words.append(mutated)
        self.words_smithed += 1

    def rewind(self):
        mutated = ""
        wrd = input("This is my linear way of reversing, please give me a word: ")
        for i in wrd:
            mutated = i + wrd
        print(mutated)
        self.words.append(mutated)
        self.words_smithed += 1

    def splice_and_dice(self):
        flag = True
        wrd = input("Please give me a word to splice up reverse style for ya: ")
        if wrd.isalpha():
            mutated = wrd[::-1]
            print("spliced up just for ya")
            print(mutated)
            self.words.append(mutated)
            self.words_smithed += 1
        else:
            while flag:
                wrd = input("That's not a word. No numbers, please try again: ")
                if wrd.isalpha():
                    flag = False
                    mutated = wrd[::-1]
                    print(mutated)
                    self.words.append(mutated)
                    self.words_smithed += 1

    def word_play(self):
        word = input("Give me a word to have fun with: ")
        out = word
        front = out[0:2]
        end = out[-2:]
        smithed_wrd = front + word + end
        print(smithed_wrd)
        self.words.append(smithed_wrd)
        self.words_smithed += 1

    """ 
    Driver methods to test program
    """
    def smith_greeting(self):
       
        seed_file = "C:/Users/mpark/Documents/GitHub/WordWorld/word_world/anvil"
        with open(seed_file) as pre_forger_items:
            print(pre_forger_items.read())

        print("\n")
        print("Greetings " + self.name.title() + "!")
        print("I am the WordSmith, how can I be of service?")
        choice = input("Enter the numbers in order to start the Word Forge up\n1: Prime the forge for word smithing \n2: Now smith the words \n3: Get the details from the forge \n4: Store words in the vault \n5: Quit \n")
        self.service(choice)
      
    def service(self, task):
        options = "Enter the numbers in order to start the Word Forge up\n1: Prime the forge for word smithing \n2: Now smith the words \n3: Get the details from the forge \n4: Store words in the vault \n5: Quit \n"

        if task == "1":
            self.auto_forge()
            
        if task == "2":
            self.smith_words()
        if task == "3":
            self.forge_details()
        
        if task == "4":
            self.vault_smithed_words()
            print("WORDS HAVE BEEN STORED IN VAULT")
       

        if task == "5":
            print("Farewell friend!")
            sys.exit()

        if task == "a":
            self.word_play()
        



        repeat = input("Another service? \n" + options + "\n")
        self.service(repeat)

    
    def auto_forge(self):
        seed = ""
        seed_file = "C:/Users/mpark/Documents/GitHub/WordWorld/word_world/pre_forge"
        with open(seed_file) as pre_forger_items:
            seed = pre_forger_items.read()
            print(pre_forger_items.read())

        
        
        self.words.append(seed)
    
    def smith_words(self):
        smithed = ""
        wrd = self.words.pop() 
        
        for i in wrd:
            smithed += i
            self.words_smithed += 1
        print(self.words_smithed)

        self.words.append(smithed)
        
    def forge_details(self):
        

        if len(self.words) >= 1:
            for i in self.words:
                print(i)
                return i
            print("::Excellent primming the forge was a success!::")
        if self.words_smithed == 209:
            print("::Perfect you have successfully smithed all the words from the file!::")

    def vault_smithed_words(self):
        txt_file = open("word_vault" + "_" + self.name.lower() + "s.txt" , "w")
        for i in self.words:
            txt_file.write(i)
        txt_file.close()
       

