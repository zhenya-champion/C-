#include "queue.h"
#include <iostream>
#include <algorithm>

std::ostream& operator << (std::ostream& stream, const QueueElement& el) {
	stream << el.data << ":" << el.pri << '\n';
	return stream;
}

Queue::Queue(size_t size):maxLength(size)
{
}

void Queue::Add(int c, int pri)
{
	if (!isFull()) {
		wait.insert(wait.begin(),{ c, pri });
	}
}

std::unique_ptr<int> Queue::Extract(int pri)
{
	if (!isEmpty()) {
		auto it = std::find_if(
		wait.rbegin(),
		wait.rend(),
			[pri](auto el) {
			return el.pri == pri;
		}
	);
	//если ничег оне нашли вернуть пустой указатель
	if (it == wait.end()) return nullptr;
	auto ret = *it;
	wait.erase(it.base());
	return std::make_unique<int>(ret.data);
    }
    return std::unique_ptr<int>();
}

std::unique_ptr<int> Queue::ExtractAndRoll(int pri)
{
	if (!isEmpty()) {
		auto it = std::find_if(
			wait.rbegin(),
			wait.rend(),
			[pri](auto el) {
				return el.pri == pri;
			}
		);
		//если ничег оне нашли вернуть пустой указатель
		if (it == wait.end()) return nullptr;
		auto ret = *it;
		wait.erase(it.base());
		wait.insert(wait.begin(), ret);
		return std::make_unique<int>(ret.data);
	}
	return std::unique_ptr<int>();
}
	

void Queue::Clear()
{
	wait.clear();
}

bool Queue::isEmpty()
{
	return wait.empty();
}

bool Queue::isFull()
{
	return wait.size() == maxLength;
}

size_t Queue::getCount()
{
	return wait.size();
}

void Queue::Show()
{
	for (auto el : wait) {
		std::cout << el << '\t';
	}
	std::cout << '\n';
}
