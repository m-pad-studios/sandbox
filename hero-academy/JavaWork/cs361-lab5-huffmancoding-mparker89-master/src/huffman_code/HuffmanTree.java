package huffman_code;



import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;

public class HuffmanTree {

    private Map<Character, Integer> frequency;
    private Map<Character, String> charPrefixHashMap;
    private PriorityQueue<HuffmanNode> priorityQueue;
    private Set<Character> keys;

    static HuffmanNode huffNodeRoot;

    public HuffmanTree() {

        frequency = new HashMap<>();
        charPrefixHashMap = new HashMap<>();
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

    public void setPrefixCodes(HuffmanNode hufNode, StringBuilder prefix){
        if(hufNode != null){
            if(hufNode.left == null && hufNode.right == null){
                charPrefixHashMap.put(hufNode.data, prefix.toString());
            } else {
                prefix.append('0');
                setPrefixCodes(hufNode.left, prefix);
                prefix.deleteCharAt(prefix.length() - 1);

                prefix.append('1');
                setPrefixCodes(hufNode.right, prefix);
                prefix.deleteCharAt(prefix.length() - 1);
            }
        }
    }

    public PriorityQueue<HuffmanNode> getHuffPriorityQueue() {
        return priorityQueue;
    }

    public Map<Character, String> getCharPrefixHashMap(){
        return charPrefixHashMap;
    }

    public Map<Character, Integer> getFrequency(){
        return frequency;
    }
}
