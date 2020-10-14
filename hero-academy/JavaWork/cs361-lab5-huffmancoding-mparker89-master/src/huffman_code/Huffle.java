package huffman_code;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.Scanner;

public class Huffle {
    HuffmanCoder huffy = new HuffmanCoder();
    private boolean unlock = false;

    public Huffle() throws IOException {
        openingMessage();
    }

    /*
    *Gets users input
    * @param String prompt
    */
    private String getInput(String prompt) {
        var scanner = new Scanner(System.in);
        System.out.print(prompt);
        return scanner.next();
    }

    /*
    *Starts the program
    */
    public void commandDeck() throws IOException {

        String createFileOrNo = getInput("Would you like to create a file with a message?");
        if(createFileOrNo.equals("y")){

        createFile();
        commands();
    }
        else if (createFileOrNo.equals("n")) {
            commands();
        }

    }

    /*
    *Main menu for program
    */
    public void commands() throws IOException {

        String choice = "";
        String text = "";
        String border = "border";

        do {
            System.out.println(huffy.decodedHuffmanText(border));

            choice = getInput("Enter option: ").trim();


            switch (choice) {
                case "1":
                    text = getInput("Please enter file name: ");
                    huffy.encodedHuffmanText(text);
                    System.out.println("FILE SUCCESSFULLY ENCODED!");
                    System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                    break;
                case "2":
                    text = getInput("Please enter file name: ");
                    System.out.println(huffy.decodedHuffmanText(text));
                    System.out.println("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                    break;
                case "3":
                    text = getInput("Please enter file name: ");
                    huffy.viewHuffmanCodeMapping(text);
                    break;
                case "4":
                    text = getInput("Please enter file name: ");
                    huffy.viewCharCodeMapping(text);
                    break;
                case "5":
                    text = getInput("Please enter file name: ");
                    System.out.println("HERE IS THE EXACT COUNT OF CHARACTERS IN THE .HUFFLE IMAGE :" + "--->[" + huffy.viewCharCount(text) + "]<---");
                    break;
                case "6":
                    text = getInput("Please enter file name: ");
                    DecimalFormat decimalFormater = new DecimalFormat("00.00");
                    var output = decimalFormater.format(huffy.spaceInfo(text));
                    System.out.println("TIME SPACE RATIOS BETWEEN: original text & encoded original text: " + output);
                    break;
                case "7":
                    HuffleShip ship = new HuffleShip();
                    break;
                case "9":
                    System.out.println("EXITING HUFFLE SYSTEM...GOODBYE :D");
                    break;
                default:
                    System.out.println("Invalid option.  Please try again.");
                    break;
            }
        } while (!choice.equals("9"));
    }

    /*
    *Login method to program
    */
    public void openingMessage() throws IOException {
        String enter;
        do {
            System.out.println();
            System.out.print("||-O-|| ||-O-|| WELCOME TO HUFFY INDS. ||-O-|| ||-O-||\n");

            System.out.println("We are a space research organization that specializes in a compressor that has technology for lossless data! \n" +
                    "Here is an example of what our HUFFLE Compressor compresses from HUBBLE...");
            System.out.print("         *                 *                  *              *\n" +
                    "                                                      *             *\n" +
                    "                        *            *                             ___\n" +
                    "  *               *                                          |     | |\n" +
                    "        *              _________##                 *        / \\    | |\n" +
                    "                      @\\\\\\\\\\\\\\\\\\##    *     |              |--o|===|-|\n" +
                    "  *                  @@@\\\\\\\\\\\\\\\\##\\       \\|/|/            |---|   |d|\n" +
                    "                    @@ @@\\\\\\\\\\\\\\\\\\\\\\    \\|\\\\|//|/     *   /     \\  |w|\n" +
                    "             *     @@@@@@@\\\\\\\\\\\\\\\\\\\\\\    \\|\\|/|/         |  U    | |b|\n" +
                    "                  @@@@@@@@@----------|    \\\\|//          |  S    |=| |\n" +
                    "       __         @@ @@@ @@__________|     \\|/           |  A    | | |\n" +
                    "  ____|_@|_       @@@@@@@@@__________|     \\|/           |_______| |_|\n" +
                    "=|__ _____ |=     @@@@ .@@@__________|      |             |@| |@|  | |\n" +
                    "____0_____0__\\|/__@@@@__@@@__________|_\\|/__|___\\|/__\\|/___________|_|_");
            enter = getInput("\nTYPE [ h ] TO ENTER: ");
            switch (enter) {
                case "h":
                    unlock = true;
                    commandDeck();
                    break;

                default:
                    System.out.println("Invalid option.  Please try again.");
                    break;
            }
        }while(unlock != true);
    }

    /*
     * Accept message to create .txt file to encode
     * */
    public void createFile() throws IOException {

        String path = "ascii_images\\";
        String file_name = getInput("Please enter a name for your file: ");

        try {
            File myObj = new File(path + file_name + ".txt");
            if (myObj.createNewFile()) {
                System.out.println("File created: " + myObj.getName());
            } else {
                System.out.println("File already exists.");
            }
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        String message = getInput("Please enter a message to write to file: ");
        try {
            FileWriter myWriter = new FileWriter(path + file_name + ".txt");
            myWriter.write(message);
            myWriter.close();
            System.out.println("Successfully wrote to the file.");
        } catch (IOException e) {
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
    }
}
