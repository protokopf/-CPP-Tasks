#pragma once

template <typename Type>
struct Node
{
	Node *leftNode = nullptr;
	Node *rightNode = nullptr;
	Type data;
};

template <typename Type>
class NodeCopier
{
public:
	NodeCopier();

	Node<Type>* GetFullCopiedNode(Node<Type>* parent);

	~NodeCopier();
};

template<typename Type>
NodeCopier<Type>::NodeCopier()
{
}

template <typename Type>
Node<Type>* NodeCopier<Type>::GetFullCopiedNode(Node<Type>* parent)
{
	Node<Type>* node = new Node < Type > ;
	node->data = parent->data;
	if (parent->leftNode != nullptr)
		node->leftNode = GetFullCopiedNode(parent->leftNode);
	if (parent->rightNode != nullptr)
		node->rightNode = GetFullCopiedNode(parent->rightNode);
	return node;
}


template<typename Type>
NodeCopier<Type>::~NodeCopier()
{
}
