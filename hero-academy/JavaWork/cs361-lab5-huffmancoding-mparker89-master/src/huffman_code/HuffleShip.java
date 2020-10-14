package huffman_code;

import java.io.IOException;
import java.util.Scanner;

/*
 * A class to showcase the use of the HuffmanCoder.
 * Simple little game the user follows along.
 * */
public class HuffleShip {

    HuffmanCoder huffy = new HuffmanCoder();
    boolean gameOver = false;
    boolean gameWon = false;
    boolean dataSlate = false;
    boolean plasmaThrower = false;


    public HuffleShip() throws IOException {

        observationMission();
    }

    private String getInput(String prompt) {
        var scanner = new Scanner(System.in);
        System.out.print(prompt);
        return scanner.next();
    }

    /*
    *Starts an observation mission.
    */
    public void observationMission() {

        System.out.println(huffy.decodedHuffmanText("mission"));
        var command = getInput("Enter ship? ");

        if (command.equals("y")) {

            System.out.println(huffy.decodedHuffmanText("door"));
            command = getInput("TO CONTINUE [c]: ");

            if (command.equals("c")) {
                System.out.println(huffy.decodedHuffmanText("ui") + huffy.decodedHuffmanText("honeyComb"));
                System.out.println("THIS IS OUR NEWLY ADVANCED UI SYSTEM CALLED - The HoneyComb. \nANYTHING WITHIN A SINGLE COMB IS AUTOMATICALLY LINKED TO THE HIVE COMB\n" +
                        "ALLOWING FOR ASYNCHRONIZED FUNCTIONALITY. THE SYMBOLS ARE ENCYPTED & YOUR KEY IS THE ONLY WAY TO READ IT.");
                command = getInput("Travel to destination? [y] : ");
            }

            if (command.equals("y")) {

                decisions(command);

            } else if (command.equals("n")) {
                System.out.println("MISSION ABORTED - BACK TO SHIP ENTRANCE");
                observationMission();
            }

        } else if (command.equals("n")) {
            System.out.println("MISSION ABORTED - BACK TO MAIN MENU");
        }

    }

    /*
     *Reads in the commands for the game.
     */
    public void decisions(String choice) {
        if (choice.equals("y")) {

            System.out.println(huffy.decodedHuffmanText("takeOff"));

            String enter = getInput("TO CONITNUE ENTER [c]: ");
            System.out.println(huffy.decodedHuffmanText("uss_e"));
            System.out.println("[[[[[[ENTERING HYPERDRIVE!]]]]]]");
            choice = getInput("APPROACHING DESTINATION...EXIT HYPERDRIVE? [y] : ");
            if (choice.equals("y")) {
                System.out.println("SUCCESSFULLY ARRIVED IN THE BEAN SOLAR SYSTEM");
                System.out.println(huffy.decodedHuffmanText("garbanzo"));
                System.out.println(huffy.decodedHuffmanText("landing"));

                choice = getInput("INITIATE LANDING? ");
                if (choice.equals("y")) {
                    System.out.println(huffy.decodedHuffmanText("briefing"));
                    if (choice.equals("y")) {
                        choice = getInput("TRAVEL TO DATA FACILITY?");
                        mission(choice);
                    }
                }
            } else if (choice.equals("n")) {
                noCommand(choice);
            }
        }
    }

    /*
    *Starts a mission. Only one installed so far.
    */
    public void mission(String command) {
        if (command.equals("y")) {

            System.out.println(huffy.decodedHuffmanText("spaceCastle"));
            command = getInput("ENTER THE DATA FACILITY?");
            if (command.equals("y")) {

                insideFacility(command);
            }

        } else if (command.equals("n")) {
            noCommand(command);
        }
    }

    /*
    *Inside facility controls.
    */
    public void insideFacility(String command){

        System.out.println(huffy.decodedHuffmanText("hallway"));
        command = getInput("Which way Sir? *as your A.I. Peppa-T asks*: TYPE right OR left: ");

        if (command.equals("left")) {

            dataSlate = true;
            System.out.println(huffy.decodedHuffmanText("dataRoom"));
            System.out.println(huffy.decodedHuffmanText("datatSlate"));
            command = getInput("We found it! Let's grab the data slate and get out of here! TYPE [g] TO GRAB: ");

            if (command.equals("g") && dataSlate == true) {

                System.out.println(huffy.encodedHuffmanText("xeno"));
                System.out.println("FROM ENCODED ENTRY OUR DATABASES DETECT THIS IS A: XENO-MORPH. HIGHLY DANGEROUS. YOU'RE PRETTY MUCH SCREWED.");
                System.out.println(huffy.decodedHuffmanText("xeno"));
                command = getInput("Let's get out of here...*as you turn around a massive form blocks the doorway* \nHOLY SHIT WTF IS THAT!!! Quick encode a log of it and blast the bastard! TYPE [b] TO BLAST: ");

                if(command.equals("b")){

                    System.out.print(huffy.decodedHuffmanText("rayGun") + huffy.decodedHuffmanText("dust"));
                    System.out.println("*Peppa-T pulls out a ray gun and insta blasts it, everyone stops and stares in confusion.* What? I found it along the way.");
                    System.out.println("We need to get out of here my scanners detect the entrance is flooded with xeno's. A ship! Let's take it.");
                    command = getInput("TAKE SHIP & BLAST OFF HOME? TYPE [y]: ");

                    if (command.equals("y")){
                        gameWon = true;
                        System.out.print(huffy.decodedHuffmanText("escapeShip"));

                    }
                }

            }

        }
        if (command.equals("right")) {
            System.out.println(huffy.decodedHuffmanText("gunRoom"));
            command = getInput("Woah a plasma thrower! Grab it. TYPE [g] TO GRAB or TYPE [n] TO MOVE PAST: ");
            if (command.equals("g")) {
                plasmaThrower = true;
                System.out.println(huffy.decodedHuffmanText("xeno"));
                command = getInput("Let's get out of here...*as you turn around a massive form blocks the doorway* \nHOLY SHIT WTF IS THAT!!! Quick encode a log of it and burn the bastard! TYPE [f] TO FLAME");
                System.out.println(huffy.decodedHuffmanText("burn"));

                System.out.println("We need to get out of here my scanners detect the entrance is flooded with xeno's. A ship! Let's take it.");
                command = getInput("TAKE SHIP & BLAST OFF HOME? TYPE [y]: ");

                if (command.equals("y")){
                    gameWon = true;
                    System.out.print(huffy.decodedHuffmanText("escapeShip"));

                }
            } else if (command.equals("n")) {
                gameOver = true;
                System.out.println(huffy.decodedHuffmanText("xeno"));
                System.out.println("YOU'VE BEEN EATEN...GAME OVER :(");
            }
        }
    }

    /*
     *Starts over from launch command.
     */
    public void noCommand(String no) {
        if (no.equals("n")) {
            var choice = getInput("Would you like to start over? ");
            decisions(choice);
        }
    }

}
