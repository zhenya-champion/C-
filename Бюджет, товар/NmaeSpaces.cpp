#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "xml.h"
#include "json.h"

using namespace std;

struct Spending {
	string category;// ��������� ������
	int amount;// ���-�� �����

};
int CalculateTotalSpending(
	const vector<Spending>& spendings
	) {// ����� ���� ������������ �����
	int result = 0;
	for (const Spending& s : spendings) {
		// ������ �� ������� ������
		result += s.amount;
	}
	return result;
}

string MostExpensiveCategory(
	const vector<Spending>& spendings
	) {// ������ �������� ��������� ���������

	// ���������� ��� ��������� ���������
	auto compare_by_amount = [](const Spending& ihs, const Spending& rhs) {
		return ihs.amount < rhs.amount;
	};
	return max_element(begin(spendings), end(spendings), compare_by_amount
		)->category;
}

vector<Spending> LoadFromXml(istream& stream)
{
	Xml::Document doc = Xml::Load(stream);
	vector<Spending> result;
	for (const Xml::Node& node : doc.GetRoot().Children()) {
		result.push_back(
			{
				node.AttributeValue<string>("category"),
				node.AttributeValue<int>("amount"),
			}
		);
	}
	return result;
}

vector<Spending> LoadFromJson(istream& stream) {
	json::Document doc = json::Load(stream);
	vector<Spending> result;
	for (const json::Node& node : doc.GetRoot().AsArray()) {
		result.push_back(
			{
				node.AsMap().at("category").AsString(),
				node.AsMap().at("amount").AsInt()
			}
			);
	}
	return result;
}

int main() {
	setlocale(0, "rus");

	ifstream stream("1.json");
	if (!stream.is_open())
	{
		return -1;
	}
	const vector<Spending> spendings = LoadFromJson(stream);
		stream.close();

	cout << "�����: " << CalculateTotalSpending(spendings) << endl;
	cout << "�������� ������� ���������: " << MostExpensiveCategory(spendings) << endl;
}

