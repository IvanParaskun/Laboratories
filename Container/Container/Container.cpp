#include <iostream>
#include <vector>
#include <string>

#include "TrollManager.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	TrollManager trollManager;

	while (true) {
		trollManager.getCommand();
		trollManager.executeCommand();
	}

}
