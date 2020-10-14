package huffman_code;

import java.io.IOException;

import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class HuffmanCoder implements IHuffman {

    HuffmanTree huffy = new HuffmanTree();

    /*
     * Display the characters found in the file and their associated counts.
     * @param String count
     * */
    public int viewCharCount(String count) {

        var sum = 0;
        encodedHuffmanText(count);
        for (var i = 0; i < count.length(); ++i) {
            sum += count.charAt(i);
        }
        return sum;
    }


    /*
     * Display the character and its associated Huffman code.
     * @param String count
     * */
    public void viewCharCodeMapping(String mapping) {

        encodedHuffmanText(mapping);
        System.out.println("\nTHE  PREFIX CHARACTER MAPPING : ");
        System.out.println(huffy.getCharPrefixHashMap());
    }

    /*
     * Display the Huffman code and its character mapping.
     * @param String count
     * */
    public void viewHuffmanCodeMapping(String huffmanMapping) {
        encodedHuffmanText(huffmanMapping);
        System.out.println("\nTHE FREQUENCY MAPPING OF CHARACTERS : ");
        System.out.println(huffy.getFrequency());
    }

    /*
     *  Display the Huffman encoded text.
     * */
    public String encodedHuffmanText(String filePath) {
        filePath = "ascii_images/" + filePath + ".txt";


        StringBuilder sBuilder = new StringBuilder();
        try (Stream<String> stream = Files.lines(Paths.get(filePath), StandardCharsets.UTF_8)) {
            stream.forEach(s -> sBuilder.append(s).append("\n"));
        } catch (IOException e) {
            e.printStackTrace();
        }

        var image = sBuilder.toString();

        for (int i = 0; i < image.length(); ++i) {
            if (!huffy.getFrequency().containsKey(image.charAt(i))) {
                huffy.getFrequency().put(image.charAt(i), 0);
            }
            huffy.getFrequency().put(image.charAt(i), huffy.getFrequency().get(image.charAt(i)) + 1);
        }
        huffy.huffNodeRoot = huffy.buildHuffmanTree(huffy.getFrequency());

        huffy.setPrefixCodes(huffy.huffNodeRoot, new StringBuilder());

        StringBuilder sB2 = new StringBuilder();
        for (var i = 0; i < sBuilder.length(); ++i) {
            char character = sBuilder.charAt(i);
            sB2.append(huffy.getCharPrefixHashMap().get(character));
        }

        return sB2.toString();
    }

    /*
     *Display the decoded text (take the encoded text and decode it back to ASCII text).
     * */
    public String decodedHuffmanText(String decodedText) {

        var codedText = encodedHuffmanText(decodedText);

        StringBuilder sBuilder = new StringBuilder();

        HuffmanNode temp = huffy.huffNodeRoot;
        //prints my long 1s and 0s
        //System.out.println("ENCODED :" + codedText);
        for (int i = 0; i < codedText.length(); ++i) {
            int j = Integer.parseInt(String.valueOf(codedText.charAt(i)));

            if (j == 0) {
                temp = temp.left;
                if (temp.left == null && temp.right == null) {
                    sBuilder.append(temp.data);
                    temp = huffy.huffNodeRoot;
                }
            }
            if (j == 1) {
                temp = temp.right;
                if (temp.left == null && temp.right == null) {
                    sBuilder.append(temp.data);
                    temp = huffy.huffNodeRoot;
                }
            }
        }

        return sBuilder.toString();
    }

    /*
     *Display the ratio between the original text and the encoded text.
     * */
    public double spaceInfo(String originalText) {

        var encoded = encodedHuffmanText(originalText);

        int e = encoded.length();
        String o = decodedHuffmanText(originalText);

        var ratios = (e / 8.0);

        var ratiosComplete = (ratios / o.length());


        return ratiosComplete;
    }

}
