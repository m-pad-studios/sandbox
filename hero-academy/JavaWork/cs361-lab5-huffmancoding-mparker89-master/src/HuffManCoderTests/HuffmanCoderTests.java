package HuffManCoderTests;


import huffman_code.HuffmanCoder;
import org.junit.Before;
import org.junit.Test;

import static junit.framework.Assert.assertNotNull;
import static junit.framework.TestCase.assertEquals;

public class HuffmanCoderTests {

        HuffmanTree huffy = new HuffmanTree();
        static HuffmanNode huffmanRoot;
    @Before
    public void setup(){

    }

    /*
    * HUFFMANTREE TESTS: STARTS
    */
    @Test
    public void isEmpty_HuffmanTree() {
        var huffy = new HuffmanTree();

        assertEquals(true, huffy.getHuffTree().isEmpty());
    }

    @Test
    public void isEmpty_HuffmanPriorityQueue(){

       huffmanRoot = huffy.buildHuffmanTree(huffy.getHuffTree());
        assertEquals(false, huffy.getHuffPriorityQueue().size() > 0);
    }

    @Test
    public void isNotEmpty_HuffmanPriorityQueue() {
        huffy.getHuffTree().put('M', 1);
        huffmanRoot = huffy.buildHuffmanTree(huffy.getHuffTree());
        huffy.getHuffPriorityQueue().offer(huffmanRoot);
        assertEquals(true, huffy.getHuffPriorityQueue().size() > 0);
    }

    @Test
    public void checkHuffmanNode_Creation(){
        HuffmanNode huffmanNode = new HuffmanNode();
        assertEquals(false, huffmanNode.equals(null));
    }

    @Test
    public void checkHuffmanNode_WithNull(){

        HuffmanNode huffmanNode = new HuffmanNode();
        huffmanNode.data = 1;
        huffmanNode.left = null;
        huffmanNode.right = null;

        assertNotNull(huffmanNode);
    }

    @Test
    public void checkHuffmanNode_Frequency(){

    }
    /*
    *HUFFMANTREE TESTS: ENDS
    */

    /*
    *HUFFMAN CODER TESTS: STARTS
    */
    public void checkHuffmanCoder_ObjectInstantiation_Success(){
        HuffmanCoder huffmanCoder = new HuffmanCoder();

        assertNotNull(huffmanCoder);
    }
    /*
    *HUFFMAN CODER TESTS: ENDS
    */

    }
