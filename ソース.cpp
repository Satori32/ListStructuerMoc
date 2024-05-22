#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
template<class StringContainer =std::string>
struct LineList {
	struct Node {
		StringContainer Title;
		StringContainer Text;
		//std::vector<std::uint8_t> Binary;
	};

	typedef StringContainer String;

	
	Node& operator [](std::size_t N) {
		return Data[N];
	}

	typename std::vector<Node>::iterator begin() {
		return Data.begin();
	}

	typename std::vector<Node>::iterator end() {
		return Data.end();
	}

	bool Push(const StringContainer& Title, const StringContainer& Text) {
		if (Find(*this, Title)) return false;
		Data.push_back({ Title,Text });
		return true;
	}

	bool Erase(const StringContainer& Title) {
		auto it = std::find_if(Data.begin(), Data.end(), [&](auto& o) {return o.Title == Title; });
		bool F = it != Data.end();
		Data.erase(it);
		return F;
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
template<class T>
bool Find(LineList<T> In,const T& Title){
		for (auto& o :In.Data) {
			if (o.Title == Title) { return true; }
		}
		return false;
	}
template<class T>
bool Add(LineList<T>& In,const T& Title, const T& Text) {
		if (!Find(In ,Title)) return false;

		auto& X = In.Get(Title);
		X.Text += ' '+Text;
		return true;
	}
int main() {
	LineList<> X;

	X.Title = "セカイりすと";

	X.Push("hoGE", "HAgeZ");
	Add<std::string>(X,"hoGE", "馬鹿野郎");
	auto& Y = X.Get("hoGE");

	X.Erase("hoGE");
	
}