_share/release.h
#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p) ? (p)->height : -1)
typedef enum {RB_RED, RB_BLACK} RBColor;

template <typename T> struct BinNode {
	T data;
	BinNodePosi(T) parent;
	BinNodePosi(T) lc;
	BinNodePosi(T) rc;
	int height;
	int npl;
	RBColor color;

	BinNode():
		parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED) {}
	BinNode(T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL,
		int h = 0, int l = 1, RBColor c = RB_RED) :
		data(e), parent(p), lc(lc), rc(rc), height(h), npl(l), color(c) {}

	int size();
	BinNodePosi(T) insertAsLc(T const&);
	BinNodePosi(T) insertAsRc(T const&);
	BinNodePosi(T) succ();
	template <typename VST> void travLevel(VST&);
	template <typename VST> void travPre(VST&);
	template <typename VST> void travIn(VST&);
	template <typename VST> void traavPost(VST&);

	bool operator<(BinNode const& bn) {
		return data < bn.data;
	}
	bool operator==(BinNode const& bn) {
		return data == bn.data;
	}
};

#define IsRoot(x) ( ! ( (x).parent ) )
#define IsLChild(x) (! IsRoot(x) && (&(x) == (x).parent->lc))
#define IsRChild(x) (! IsRoot(x) && (&(x) == (x).parent->rc))
#define HasParent(x) (! IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasRChild(x) || HasLChild(x))
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))
#define IsLeaf(x) (! HasChild(x))
#define sibling(p) \
	(IsLChild(*p) ? (p)->parent->rc : (p)->parent->lc)
#define uncle(x) \
	(IsLChild(* ((x)->parent)) ? (x)->parent->parent->rc : (x)->parent->parent->lc)
#define FromParentTo(x) \
	(IsRoot(x) ? _root : (IsLChild(X) ? (x).parent->lc : (x).parent->rc))

template <typename T> BinNodePosi(T) BinNode<T>::insertAsLc(T const& e) {
	return lc = new BinNode(e, this);
}
template <typename T> BinNodePosi(T) BinNode<T>::insertAsRc(T const& e) {
	return rc = new BinNode(e, this);
}

template <typename T> template <typename VST>
void BinNode<T>::travIn(VST& visit) {
	switch(rand() % 5) {
		case 1:
			travIn_I1(this, visit);
			break;
		case 2:
			travIn_I2(this, visit);
			break;
		case 3:
			travIn_I3(this, visit);
			break;
		case 4:
			travIn_I4(this, visit);
			break;
		default:
			travIn_IR(this, visit);
			break;
	}
}

template <typename T> class BinTree {
protected:
	int _size;
	BinNodePosi(T) _root;
	virtual int updateHeight(BinNodePosi(T) x);
	void updateHeightAbove(BinNodePosi(T) x);
public:
	BinTree() : _size(0), _root(NULL) {}
	~BinTree() {
		if (0 < _size)
			remove(_root);
	}
	int size() const {return _size;}
	bool empty() const {return _size;}
	BinNodePosi(T) root() const {return _root;}
	BinNodePosi(T) insertAsRoot(T const& e);
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, T const& e);
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, T const& e);
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>*& T);
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>*& T);
	int remove(BinNodePosi(T) x);
	BinTree<T>* secede(BinNodePosi(T) x);
	template <typename VST>
	void travLevel(VST& visit) {
		if (_root) 
			_root->travLevel(visit);
	}
	template <typename VST>
	void travPre(VST& visit) {
		if (_root)
			_root->travPre(visit);
	}
	template <typename VST>
	void travIn(VST& visit) {
		if (_root)
			_root->travIn(visit);
	}
	template <typename VST>
	void travPost(VST& visit) {
		if (_root) 
			_root->travPost(visit);
	}
	bool operator<(BinTree<T> const& t) {
		return _root && t._root && lt(_root, t._root);
	}
	bool operator==(BinTree<T> const& t) {
		return _root && t._root && (_root == t._root);
	}
};

template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x) {
	return x->height = 1 + max(stature(x->lc), stature(x->rc));
}
template <typename T>
void BinTree<T>::updateHeightAbove(BinNodePosi(T) x) {
	while (x) {
		updateHeight(x);
		x = x->parent;
	}
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e) {
	_size = 1;
	return _root = new BinNode<T>(e);
}
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e) {
	_size++;
	x->insertAsLc(e);
	updateHeightAbove(x);
	return x->lc;
}
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e) {
	_size++;
	x->insertAsRc(e);
	updateHeightAbove(X);
	return x->rc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>*& s) {
	if (x->rc = s->_root)
		x->rc->parent = x;
	_size += s->size();
	updateHeightAbove(x);
	s->_root = NULL;
	s->_size = 0;
	release(s);
	s = NULL;
	return x;
}
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>*& s) {
	if (x->lc = s->_root)
		x->lc->parent = x;
	_size += s->size();
	updateHeightAbove(x);
	s->_root = NULL;
	s->_size = 0;
	release(s);
	s = NULL;
	return x;
}

template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x) {
	FromParentTo(*x) = NULL;
	updateHeightAbove(x->parent);
	int n = removeAt(x);
	_size -= n;
	return n;
}
template <typename T>
static int removeAt(BinNodePosi(T) x) {
	if (!x) return 0;
	int n = 1 + removeAt(x->lc) + removeAt(x->rc);
	release(x->data);
	release(x);
	return n;
}

template <typename T>
BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x) {
	FromParentTo(*x) = NULL;
	updateHeightAbove(x->parent);
	BinTree<T>* s = new BinTree<T>;
	s->_root = x;
	x->parent = NULL;
	s->_size = x->size();
	return s;
}

template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST& visit) {
	if (!x) return;
	visit(x->data);
	travPre_R(x->lc, visit);
	travPre_R(x->rc, visit);
}

template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST& visit) {
	if (!x) return;
	travPost_R(x->lc, visit);
	travPost_R(x->rc, visit);
	visit(x->data);
}

template <typename T, typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S) {
	while (x) {
		visit(x);
		S.push(x->rc);
		x = x->lc;
	}
}
template <typename T, typename VST>
void travPre_I2(BinNodePosi(T) x, VST& visit) {
	Stack<BinNodePosi(T)> S;
	while (true) {
		visitAlongLeftBranch(x, visit, S);
		if (S.empty()) 
			break;
		x = S.pop();
	}
} 

template <typename T>
static void goAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T)>& S) {
	while (true) {
		S.push(x);
		x = x->lc;
	}
}
template <typename T, typename VST>
void travIn_I1(BinNodePosi(T) x, VST& visit) {
	Stack<BinNodePosi(T)> S;
	while (true) {
		goAlongLeftBranch(x, S);
		if (S.empty())
			break;
		x = S.pop();
		visit(x->data);
		x = x->rc;
	}
}

template <typename T>
BinNodePosi(T) BinNode<T>::succ() {
	BinNodePosi(T) s = this;
	if (rc) {
		s = rc;
		while (HasLChild(*s)) {
			s = s->lc;
		}
	}
	else {
		while (IsRChild(*s)) {
			s = s->parent;
		}
		s = s->parent;
	}
	return s;
}
template <typename T, typename VST>
void travIn_I2(BinNodePosi(T) x, VST& visit) {
	Stack<BinNodePosi(T)> S;
	while (true) {
		if (x) {
			S.push(x);
			x = x->lc;
		}
		else if (!S.empty()) {
			x = S.pop();
			visit(x->data);
			x = x->rc;
		}
		else
			break;
	}
}

template <typename T, typename VST>
void travIn_I3(BinNodePosi(T) x, VST& visit) {
	bool backtrack = false;
	while (true) {
		if (!backtrack && HasLChild(*x)) {
			x = x->lc;
		}
		else {
			visit(x->data);
			if (HasRChild(*x)) {
				x = x->rc;
				backtrack = false;
			}
			else {
				if (!(x = x->succ()))
					break;
				backtrack = true;
			}
		}
	}
}

template <typename T>
static void gotoHLVFL(Stack<BinNodePosi(T)>& S) {
	while (BinNodePosi(T) x = S.top()) {
		if (HasLChild(*x)) {
			if (HasRChild(*x)) {
				S.push(x->rc);
			}
			S.push(x->lc);
		}
		else {
			S.push(x->rc);
		}
	}
	S.pop();
}
template <typename T, typename VST>
void travPost_I(BinNodePosi(T) x, VST& visit) {
	Stack<BinNodePosi(T)> S;
	if (x)
		S.push(x);
	while (!S.empty()) {
		if (S.top() != x->parent)
			gotoHLVFL(S);
		x = S.pop();
		visit(x->data);
	}
}

template <typename T, typename VST>
void BinNode<T>::travLevel(VST& visit) {
	Queue<BinNodePosi(T)> Q;
	Q.enqueue(this);
	while (!Q.empty()) {
		BinNodePosi(T) x = Q.dequeue();
		visit(x->data);
		if (HasLChild(*x))
			Q.enqueue(x->lc);
		if (HasRChild(*x)) 
			Q.enqueue(x->rc); 
	}
}