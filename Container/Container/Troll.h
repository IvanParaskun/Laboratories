#include <vector>
#include <string>

using namespace std;

class Troll {
public:
	string name;
	vector<string> stops;

	void addStop(string stop) {
		this->stops.push_back(stop);
	}

	void printStops() {
		for (int i = 0; i < stops.size(); i++) {
			cout << stops[i] << " ";
		}

		cout << "" << endl;
	}
};