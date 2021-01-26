'''
LeetCode:  https://leetcode.com/problems/serialize-and-deserialize-binary-tree
'''

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Codec:

    def __init__(self):
        self.i = 0

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if not root:
            return "null"
        return str(root.val) + "," + self.serialize(root.left) + "," + self.serialize(root.right)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        print(data)

        def buildTree(nodes):
            if nodes[self.i] != "null":
                root = TreeNode(int(nodes[self.i]))
                self.i += 1
                root.left = buildTree(nodes)
                self.i += 1
                root.right = buildTree(nodes)
                return root
            else:
                return None

        if data == "null":
            return None
        nodes = data.split(",")
        return buildTree(nodes)


# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))
