#ifndef TREE_NODE
#define TREE_NODE

// template<class T>
class TreeNode
{
public:
    explicit TreeNode();
    explicit TreeNode(int value);
    explicit TreeNode(const TreeNode &other);

    int value() const;

    TreeNode *left() const;
    TreeNode *right() const;

private:
    int _value;

    TreeNode *_left { nullptr };
    TreeNode *_right { nullptr };
};

#endif // TREE_NODE