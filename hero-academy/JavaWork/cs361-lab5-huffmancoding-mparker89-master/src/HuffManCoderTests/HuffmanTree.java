package HuffManCoderTests;

import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

public class HuffmanTree {


    private Map<Character, Integer> huffTree;
    private Map<Character, String> charPrefixHashMap;
    private PriorityQueue<HuffmanNode> priorityQueue;
    private Set<Character> keys;

    static HuffmanNode huffNodeRoot = null;

    public HuffmanTree() {

        charPrefixHashMap = new HashMap<>();
        huffTree = new HashMap<>();
        priorityQueue = new PriorityQueue<>();
    }

    public HuffmanNode buildHuffmanTree(Map<Character, Integer> frequencyMapping) {

        keys = frequencyMapping.keySet();
        for (var c : keys) {

            HuffmanNode huffmanNode = new HuffmanNode();
            huffmanNode.data = c;
            huffmanNode.frequency = frequencyMapping.get(c);
            huffmanNode.left = null;
            huffmanNode.right = null;
            priorityQueue.offer(huffmanNode);

        }

        while (priorityQueue.size() > 1) {

            HuffmanNode huffNodeLeft = priorityQueue.peek();
            priorityQueue.poll();

            HuffmanNode huffNodeRight = priorityQueue.peek();
            priorityQueue.poll();

            HuffmanNode sum = new HuffmanNode();

            sum.frequency = huffNodeLeft.frequency + huffNodeRight.frequency;
            sum.data = '-';

            sum.left = huffNodeLeft;
            sum.right = huffNodeRight;
            huffNodeRoot = sum;

            priorityQueue.offer(sum);
        }

        return priorityQueue.poll();
    }

    public static void setPrefixCodes(HuffmanNode hufNode, StringBuilder prefix){
        if(hufNode != null){
            if(hufNode.left == null && hufNode.right == null){

            }
        }
    }

    public Map<Character, Integer> getHuffTree() {
        return huffTree;
    }

    public PriorityQueue<HuffmanNode> getHuffPriorityQueue() {
        return priorityQueue;
    }

    public Map<Character, String> getCharPrefixHashMap(){
        return charPrefixHashMap;
    }
}
