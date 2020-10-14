package HuffManCoderTests;


public class HuffmanNode implements Comparable<HuffmanNode> {

    int frequency;
    char data;

    HuffmanNode left;
    HuffmanNode right;

    @Override
    public int compareTo(HuffmanNode huffNode) {
        return frequency - huffNode.frequency;
    }

}
