#include <iostream>
#include <exception>

using namespace std;

struct point{
	int x;
	int y;
};
struct rect{
	int x2;
	int y2;
	int x1;
	int y1;
public:
	point operator[](const int& index) {
		if(index < 0 || index > 3) throw IndexException();

		point res;

		switch(index)
		{
		case 0: res = { x1, y1 }; break;
		case 1: res = { x2, y1 }; break;
		case 2: res = { x2, y2 }; break;
		case 3: res = { x1, y2 }; break;
		}
		return res;
	}
private:
	class IndexException : public exception {
	public:
		const char* what() {
			return "index error : no data for the index";
		}
	};
	struct iterator
	{
		iterator(rect* const ptr , const int& index = 0) : object_pointer(ptr), property_index(index) {}

		point operator*() const { if ((property_index < 0) || (property_index > 3))throw IndexException(); 
		return (*object_pointer)[property_index]; }

		iterator & operator++ ()
			{
 property_index++; 
 return *this;
}

friend bool operator!= (const iterator & left_, const iterator & right_)
	{
return left_.property_index != right_.property_index;
};
private:
	rect* object_pointer;
	int property_index;
};
public:
	iterator begin() { 
		return iterator(this, 0); 
	}
	iterator end() { 
		return iterator(this, 4); 
	}
};

rect get_work_rect() {
	rect e;
	cout << "input rect left upper corner point : \n";
	cin >> e.x1 >> e.y1;
	cout << "input rect right lower corner point : \n";
	cin >> e.x2 >> e.y2;
	return e;
}

void process_point(point pt) {
	cout << "(" << pt.x << ", " << pt.y << ")";
}
void process_rect(rect r) {
	for(int y = r.y1; y < r.y2; ++y)
		for(int x = r.x1; x < r.x2; ++x) {
		process_point(point{ x,y });
	}
}

int main() {
	rect r = get_work_rect();
	for (auto p : r) {
		process_point(p);
	}
	return 0;
}
