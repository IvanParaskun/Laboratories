#include <vector>
#include <string>
#include "Troll.h"

using namespace std;

enum class Command {
	CREATE_TRL,
	TRL_IN_STOP,
	STOPS_IN_TRL,
	TRLS
};

class TrollManager {
public:
	vector<Troll> trolls;
	Command command;
	vector<string> commandP;

	void getCommand() {
		string command;
		cout << "Введите команду: ";
		getline(cin, command);

		vector<string> commandParts = splitCommand(command);

		if (commandParts[0] == "CREATE_TRL") {
			this->command = Command::CREATE_TRL;
			this->commandP = commandParts;
		}
		else if (commandParts[0] == "TRL_IN_STOP") {
			this->command = Command::TRL_IN_STOP;
			this->commandP = commandParts;
		}
		else if (commandParts[0] == "STOPS_IN_TRL") {
			this->command = Command::STOPS_IN_TRL;
			this->commandP = commandParts;
		}
		else if (commandParts[0] == "TRLS") {
			this->command = Command::TRLS;
			this->commandP = commandParts;
		}
		else {
			cout << "Неверная команда!" << endl;
			getCommand();
		}
	}

	void executeCommand() {
		switch (command) {
			case Command::CREATE_TRL:
			{
				Troll newTroll;
				newTroll.name = commandP[1];

				for (int i = 2; i < commandP.size(); i++) {
					newTroll.addStop(commandP[i]);
				}

				trolls.push_back(newTroll);
				break;
			}
				
			case Command::TRL_IN_STOP:
			{
				for (int i = 0; i < trolls.size(); i++) {
					Troll troll = trolls[i];

					if (find(troll.stops.begin(), troll.stops.end(), commandP[1]) != troll.stops.end()) {
						cout << troll.name << " ";
					}
				}

				cout << "" << endl;
				break;
			}

			case Command::STOPS_IN_TRL:
			{
				for (int i = 0; i < trolls.size(); i++) {
					Troll troll = trolls[i];

					if (troll.name == commandP[1]) {
						troll.printStops();
					}
				}

				break;
			}

			case Command::TRLS:
			{
				for (int i = 0; i < trolls.size(); i++) {
					Troll troll = trolls[i];
					cout << troll.name << ": ";
					for (int j = 0; j < troll.stops.size(); j++) {
						cout << troll.stops[j] << " ";
					}
					cout << "" << endl;
				}
				
				break;
			}
		}
	}

private:
	vector<string> splitCommand(string command) {
		vector<string> commandParts;

		auto start = 0U;
		auto end = command.find(" ");
		while (end != std::string::npos)
		{
			commandParts.push_back(command.substr(start, end - start));
			start = end + 1;
			end = command.find(" ", start);
		}

		commandParts.push_back(command.substr(start, end));

		return commandParts;
	}
};