public class PreOrderBinaryTreeInJava {
    //Creating of node class which will create new nodes
    static class node
    {
        int data;
        node left;
        node right;
        node(int data)
        {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
    static class binaryTree
    {
        //this will be incremented in order to reach full length
        static int index = -1;
        // this function will take all the nodes and will return the root node
        public static node buildTree(int Nodes[])
        {
        index++;
            if(Nodes[index]==-1)
            {
            return null;
            }
            node newNode = new node(Nodes[index]);
            newNode.left = buildTree(Nodes);
            newNode.right = buildTree(Nodes);
            return newNode;
        }
    }
    public static void main(String[] args) {
        int[] nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        binaryTree tree = new binaryTree();
        node root = tree.buildTree(nodes);
        System.out.println(root.data);
    }
}
