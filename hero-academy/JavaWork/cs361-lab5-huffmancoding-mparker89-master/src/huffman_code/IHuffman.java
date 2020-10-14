package huffman_code;

public interface IHuffman {

    int viewCharCount(String count);
    void viewCharCodeMapping(String mapping);
    String encodedHuffmanText(String encodedText);
    void viewHuffmanCodeMapping(String huffmanMapping);
    String decodedHuffmanText(String decodedText);
    double spaceInfo(String originalText);

}
