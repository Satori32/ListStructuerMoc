#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
template<class String =std::string>
struct LineList {

	enum class Progress
	{
		Zero,
		WaitStart,
		Initialize,
		Start,
		First,
		Mid,
		Later,
		End,
		waitDestruction,
		complete,
	};

	struct Node {
		Progress F=Progress::Zero;
		String Title;
		String Text;
		std::vector<std::uint8_t> Binary;
	};

	typedef String String;

	
	Node& operator [](std::size_t N) {
		return Data[N];
	}

	typename std::vector<Node>::iterator begin() {
		return Data.begin();
	}

	typename std::vector<Node>::iterator end() {
		return Data.end();
	}

	bool Push(const String& Title, const String& Text) {
		if (Find(*this, Title)) return false;

		Data.push_back({ {},Title,Text,{} });
		return true;
	}

	bool Erase(const String& Title) {
		auto it = std::find_if(Data.begin(), Data.end(), [&](auto& o) {return o.Title == Title; });
		bool F = it != Data.end();
		if (F) { Data.erase(it); }
		return F;
	}

	Node* Get(const String& Title) {
		if (!Find(*this, Title)) { return nullptr; }//little duty.

		for (auto& o : Data) {
			if (o.Title == Title) { return &o; }
		}

		return nullptr;
	}

	std::vector<Node> Data;
	std::string Title;
};
template<class T>
bool Find(LineList<T> In,const T& Title){//in.find();
		for (auto& o :In.Data) {
			if (o.Title == Title) { return true; }
		}
		return false;
	}
template<class T>
bool Add(LineList<T>& In,const T& Title, const T& Text) {
		if (!Find(In ,Title)) return false;

		auto* X = In.Get(Title);
		if (X == nullptr)return false;
		X->Text += ' '+Text;
		return true;
	}
int main() {
	LineList<> X;

	X.Title = "セカイりすと";

	X.Push("hoGE", "HAgeZ");
	Add<std::string>(X,"hoGE", "馬鹿野郎");
	auto Y = X.Get("hoGE");

	X.Erase("hoGE");

	return 0;
	
}