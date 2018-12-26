#include "../BST/BSt.h"
template <typename T> class AVL : public BST<T> {
public:
	BinNodePosi(T) insert(const T& e);
	bool remove(const T& e);
};
#define Balanced(x) ((stature((x).lc)) == stature((x).rc))
#define BalFac(x) (stature((x).lc) - stature((x).rc))
#define AvlaBalanced(x) ((-2 < BalFac(x)) && (BalFac(x) < 2))

//左右孩子取更高
#define tallerChild(x) ( \
	stature( (x)->lc ) > stature( (x)->rc ) ? (x->lc) : ( \
		stature( (x)->lc ) < stature( (x)->rc ) ? (x)->rc : ( \
			IsLChild(*(x)) ? (x)->lc : (x)->rc 
		) \
	) \
)

template <typename T>
BinNodePosi(T) AVL<T>::insert(const T& e) {
	BinNodePosi(T)& x = search(e);
	if (x) return x;
	BinNodePosi(T) xx = x = new BinNode<T>(e, _hot);
	_size++;
	for (BinNodePosi(T) g = _hot; g; g = g->parent) {
		if (!AvlaBalanced(*g)) {
			FromParentTo(*g) = rotateAt(tallerChild(tallerChild(g)));
			break;
		}
		else {
			updateHeight(g);
		}
	}
	return xx;
}