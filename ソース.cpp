#include <iostream>
#include <vector>
#include <string>

template<class StringContainer =std::string
>
struct LineList {
	struct Node {
		const StringContainer& Title;
		const StringContainer& Text;
	};

	bool Find(const const StringContainer&& Title){
		for (auto& o : Data) {
			if (o.Title == Title) { return true; }
		}
		return false;
	}
	Node& operator [](std::size_t N) {
		return Data[N];
	}

	typename std::vector<Node>::iterator begin() {
		return Data.begin();
	}

	typename std::vector<Node>::iterator end() {
		return Data.end();
	}

	bool Push(const StringContainer& Title , const StringContainer& Text) {
		if (Find(Title)) return false;
		Data.push_back({ Title,Text });
		return true;
	}

	bool Add(const StringContainer& Title, const StringContainer& Text) {
		if (Find(Title)) return false;

		auto& X = Get(Title);
		X.Text += ' '+Text;
	}

	Node& Get(const StringContainer& Title) {
		Node N{ {"Null"},{"Null"} };
		for(auto& o:Data){
			if (o.Title == Title) { return o; }
		}
		return N;
	}

	std::vector<Node> Data;
	std::string Title;
};

int main() {
	LineList<> X;
}