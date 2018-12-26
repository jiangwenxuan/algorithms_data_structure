typedef int Rank;
#define ListNodePosi(T) ListNode<T>*

template <typename T> struct ListNode {
	T data;
	ListNodePosi(T) pred;
	ListNodePosi(T) succ;

	ListNode() {}
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL) 
		: data(e), pred(p), succ(s) {}

	ListNodePosi(T) insertAsPred(T const& e);
	ListNodePosi(T) insertAsSucc(T const& e);
};

template <typename t> class List {
private:
	int _size;
	ListNodePosi(T) header;
	ListNodePosi(T) trailer;
protected:
	void init();
	int clear();
	void copyNodes(ListNodePosi(T), int);
	void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int);
	void mergeSort(ListNodePosi(T)&, int);
	void selectionSort(ListNodePosi(T), int);
	void insertionSort(ListNodePosi(T), int);
public:
	List() {init();}
	List(List<T> const& L);
	List(List<T> const& L, Rank r, int n);
	List(ListNodePosi(T) p, int n);

	~List();
	Rank size() const {return _size;}
	bool empty() const {return _size == 0;}
	T& operator[](Rank r) const;
	ListNodePosi(T) first() const {return header->succ;}
	ListNodePosi(T) last() const {return trailer->pred;}
	bool valid(ListNodePosi(T) p) {
		return p && (trailer != p) && (header != p);
	} 
	int disordered() const;
	ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;
	ListNodePosi(T) find(T const& e) {
		return find(e, _size, trailer);
	}
	ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;
	ListNodePosi(T) search(T const& e) const {
		return search(e, _size, trailer);
	}
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
	ListNodePosi(T) selectMax() {
		return selectMax(header->succ, _size);
	}
	ListNodePosi(T) insertAsFirst(T const& e);
	ListNodePosi(T) insertAsLast(T const& e);
	ListNodePosi(T) insertA(T const& e, ListNodePosi(T) p);
	ListNodePosi(T) insertB(T const& e, ListNodePosi(T) p);
	T remove(ListNodePosi(T) p);
	void merge(List<T>& L) {
		merge(first(), _size, L, L.first(), L.size());
	}
	void sort() {
		sort(first(), _size);
	}
	void sort(ListNodePosi(T) p, int n);
	int deduplicate();
	int uniquify();
	void reverse();

	void traverse(void (* ) (T& ));
	template <typename VST>
	void taverse(VST&);
};

template <typename T>
void List<T>::init() {
	header = new ListNode<T>;
	trailer = new ListNode<T>;
	header->succ = trailer;
	trailer->pred = header;
	header->pred = NULL;
	trailer->succ = NULL;
	_size = 0;
}

template <typename T>
T& List<T>::operstor[](Rank r)  const {
	ListNodePosi(T) p = first();
	while (0 < r--) 
		p = p->succ;
	return p->data;
}

template <typename T>
ListNodePosi(T) List<T>::find(T const& e, int n, ListNodePosi(T) p) const {
	while (0 < n--)
		if (e == (p = p->pred)->data)
			return p;
	return NULL;
}

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const& e) {
	_size++;
	return header->insertAsSucc(e);
}
template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const& e) {
	_size++;
	return trailer->insertAsPred(e);
}
template <typename T>
ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, T const& e) {
	_size++;
	return p->insertAsSucc(e);
}
template <typename T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(t) p, T const& e) {
	_size++;
	return p->insertAsPred(e);
}
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const& e) {
	ListNodePosi(T) x = new ListNode(e, pred, this);
	pred->succ = x;
	pred = x;
	return x;
}
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsSucc(T const& e) {
	ListNodePosi(T) x = new ListNode(e, this, succ);
	succ->pred = x;
	succ = x;
	return x;
}

template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n) {
	init();
	while (n--) {
		insertAsLast(p->data);
		p = p->pred;
	}
}

template <typename T>
List<T>::List(ListNodePosi(T) p, int n) {
	copyNodes(p, n);
}

template <typename T>
List<T>::List(List<T> const& L) {
	copyNodes(L.first(), L._size);
}

template <typename T>
List<T>::List(List<T> const& L, int r, int n) {
	copyNodes(L[r], n);
}

template <typename T>
T List<T>::remove(ListNodePosi(T) p) {
	T e = p->data;
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	delete p;
	_size--;
	return e;
}

template <typename T>
List<T>::~List() {
	clear();
	delete header;
	delete trailer;
}

template <typename T>
int List<T>::clear() {
	int oldsize = _size;
	while (0 < _size) {
		remove(header->succ);
	}
	return oldsize;
}

template <typename T>
int List<T>::deduplicate() {
	if (_size < 2) return 0;
	int oldsize = _size;
	ListNodePosi(T) p = header;
	Rank r = 0;
	while (trailer != (p = p->succ)) {
		ListNodePosi(T) q = find(p->data, r, p);
		q ? remove(q) : r++;
	}
	return oldsize - _size;
}

template <typename T>
void List<T>::traverse(void (*visit ) (T& )) {
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
		visit(p->data);
}
template <typename T> template <typename VST>
void List<T>::traverse(VST& visit) {
	for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ)
		visit(p->data);
}

template <typename T>
int List<T>::uniquify() {
	if (_size < 2) return 0;
	int oldsize = _size;
	ListNodePosi(T) p = header->succ;
	ListNodePosi(T) q;
	while (trailer != (q = p->succ)) {
		if (p->data == q->data) 
			remove(q);
		else {
			p = q;
		}
	}
}

template <typename T>
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) {
	while (0 , n--) {
		if ((p = p->pred)->data <= e)
			break;
	}
	return p;
}

template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n) {
	switch(rand() % 3) {
		case 1:
			insertionSort(p, n);
			break;
		case 2:
			selectionSort(p, n);
			break;
		default:
			mergeSort(p, n);
			break;
	}
}

template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n) {
	for (int r = 0; r < n; r++) {
		insertA(search(p->data, r, p), p->data);
		p = p->succ;
		remove(p->pred);
	}
}

template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n) {
	ListNodePosi(T) head = p->pred;
	ListNodePosi(T) tail = p;
	for (int i = 0; i < n; i++) {
		tail = tail->succ;
	}
	while (1 < n) {
		ListNodePosi(T) max = selectMax(head->succ, n);
		insertB(tail, remove(max));
		tail = tail->pred;
		n--;
	}
}

template <typename T>
void List<T>::merge(ListNodePosi(T)& p, int n, List<T>& L, ListNodePosi(T) q, int m) {
	ListNodePosi(T) pp = p->pred;
	while (0 < m) {
		if ((0 < n) && (p->data <= q->data)) {
			if (q == (p = p->succ))
				break;
			n--;
		}
		else {
			insertB(p, L.remove((q = q->succ)->pred));
			m--;
		}
	}
	p = pp->succ;
}

template <typename T>
void List<T>::mergeSort(ListNodePosi(T)& p, int n) {
	if (n < 2) return;
	int m = n >> 1;
	ListNodePosi(T) q = p;
	for (int i = 0; i < m; i++)
		q = q->succ;
	mergeSort(p, m);
	mergeSort(q, n - m);
	merge(p, m, *this, q, n-m);
}