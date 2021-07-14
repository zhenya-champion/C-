#include <iostream>
#include <conio.h>

using namespace std;

struct point {
	int x;
	int y;
};
// point1 - top left rect corner point
// point2 - bottom right rect corner point
struct rect {
public:
	int x1;
	int y1;
	int x2;
	int y2;

private:
	enum class E_ITER_SORTS {
		BEGIN,
		END
	};

public:
	class iterator {
	public:
		iterator(const rect& incoming, E_ITER_SORTS sort) {

			int x1 = incoming.x1;
			int y1 = incoming.y1;
			int x2 = incoming.x2;
			int y2 = incoming.y2;

			if (x1 > x2) {
				std::swap(x1, x2);
			}

			if (y1 > y2) {
				std::swap(y1, y2);
			}

			if (sort == E_ITER_SORTS::BEGIN)
				cout << "rect" << "({" << x1 << ", " << y1 << "}, {" << x2 << ", " << y2 << "})\n";

			top_left_x = x1;
			top_left_y = y1;

			int width = x2 - x1;
			int height = y2 - y1;

			line_x_top = top_left_x + width;
			line_y_top = top_left_y + height;

			switch (sort) {
			case E_ITER_SORTS::BEGIN:
				virtual_y = top_left_y;
				virtual_x = top_left_x;
				index = 0;
				break;
			case E_ITER_SORTS::END:
				virtual_x = line_x_top;
				virtual_y = line_y_top;
				index = (width + 1) * (height + 1);
				break;
			};
		}
	public:
		bool operator!=(iterator second) {
			return this->index != second.index;
		}

		iterator const& operator++() {
			if (virtual_x < line_x_top) {
				virtual_x++;
			}
			else {
				virtual_x = top_left_x;
				if (virtual_y < line_y_top)
					virtual_y++;
				else
					5;

			}
			index++;
			return *this;
		}
		point operator*() {
			return { virtual_x, virtual_y };
		}
	private:
		int index;
		int virtual_x;
		int virtual_y;

		int top_left_x;
		int top_left_y;
		int line_x_top;
		int line_y_top;
	};
public:
	iterator begin() {
		return iterator(*this, E_ITER_SORTS::BEGIN);
	};
	iterator end() {
		return iterator(*this, E_ITER_SORTS::END);
	};
};

void dosomething(const point& pnt) {
	cout << "(" << pnt.x << "; " << pnt.y << ")\n";
}

int main() {
	rect lol[6]{
	{3,3,6,6},
	{3,3,3,3},
	{3,6,3,8},
	{3,6,8,6},
	{6,6,3,3},
	{6,3,3,6}
	};

	for (int i = 0; i < 6; i++) {
		for (auto pnt : lol[i]) {
		dosomething(pnt);
		}
	}

	/*auto it = lol.begin();
	auto itend = lol.end();

	while (it != itend) {
	point pnt = *it;
	std::cout << "(" << pnt.x << "; " << pnt.y << ")\n";
	it++;
	_getch();
	} */

	return 0;
}