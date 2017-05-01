#include <iostream>
#include <string>
#include <tuple>
#include <stdlib.h>
#include <utility> 
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

void inc(string&, int);

vector<pair<string, vector<string>>> hiragana{};
//unordered_map<string, vector<string>> hiragana;


int main(int argc, char** argv)
{

	hiragana.push_back(make_pair("あ", vector<string> {"a"}));
	hiragana.push_back(make_pair("え", vector<string> {"e"}));
	hiragana.push_back(make_pair("い", vector<string> {"i"}));
	hiragana.push_back(make_pair("お", vector<string> {"o"}));
	hiragana.push_back(make_pair("う", vector<string> {"u"}));

	hiragana.push_back(make_pair("こ", vector<string> {"ko"}));
	hiragana.push_back(make_pair("か", vector<string> {"ka"}));
	hiragana.push_back(make_pair("く", vector<string> {"ku"}));
	hiragana.push_back(make_pair("き", vector<string> {"ki"}));
	hiragana.push_back(make_pair("け", vector<string> {"ke"}));

	hiragana.push_back(make_pair("さ", vector<string> {"sa"}));
	hiragana.push_back(make_pair("す", vector<string> {"su"}));
	hiragana.push_back(make_pair("せ", vector<string> {"se"}));
	hiragana.push_back(make_pair("そ", vector<string> {"so"}));

	hiragana.push_back(make_pair("と", vector<string> {"to"}));
	hiragana.push_back(make_pair("た", vector<string> {"ta"}));
	hiragana.push_back(make_pair("て", vector<string> {"te"}));

	hiragana.push_back(make_pair("な", vector<string> {"na"}));
	hiragana.push_back(make_pair("に", vector<string> {"ni"}));
	hiragana.push_back(make_pair("ぬ", vector<string> {"nu"}));
	hiragana.push_back(make_pair("ね", vector<string> {"ne"}));
	hiragana.push_back(make_pair("の", vector<string> {"no"}));

	hiragana.push_back(make_pair("は", vector<string> {"ha"}));
	hiragana.push_back(make_pair("ひ", vector<string> {"hi"}));
	hiragana.push_back(make_pair("ふ", vector<string> {"hu"}));
	hiragana.push_back(make_pair("へ", vector<string> {"he"}));
	hiragana.push_back(make_pair("ほ", vector<string> {"ho"}));

	hiragana.push_back(make_pair("ま", vector<string> {"ma"}));
	hiragana.push_back(make_pair("み", vector<string> {"mi"}));
	hiragana.push_back(make_pair("む", vector<string> {"mu"}));
	hiragana.push_back(make_pair("め", vector<string> {"me"}));
	hiragana.push_back(make_pair("も", vector<string> {"mo"}));

	hiragana.push_back(make_pair("や", vector<string> {"ya"}));
	hiragana.push_back(make_pair("ゆ", vector<string> {"yu"}));
	hiragana.push_back(make_pair("よ", vector<string> {"yo"}));

	hiragana.push_back(make_pair("ら", vector<string> {"ra"}));
	hiragana.push_back(make_pair("り", vector<string> {"ri"}));
	hiragana.push_back(make_pair("る", vector<string> {"ru"}));
	hiragana.push_back(make_pair("れ", vector<string> {"re"}));
	hiragana.push_back(make_pair("ろ", vector<string> {"ro"}));

	hiragana.push_back(make_pair("わ", vector<string> {"wa"}));
	hiragana.push_back(make_pair("を", vector<string> {"wo"}));

	hiragana.push_back(make_pair("ざ", vector<string> {"za"}));
	hiragana.push_back(make_pair("ず", vector<string> {"zu"}));
	hiragana.push_back(make_pair("ぜ", vector<string> {"ze"}));
	hiragana.push_back(make_pair("ぞ", vector<string> {"zo"}));

	hiragana.push_back(make_pair("が", vector<string> {"ga"}));
	hiragana.push_back(make_pair("ぎ", vector<string> {"gi"}));
	hiragana.push_back(make_pair("ぐ", vector<string> {"gu"}));
	hiragana.push_back(make_pair("げ", vector<string> {"ge"}));
	hiragana.push_back(make_pair("ご", vector<string> {"go"}));

	hiragana.push_back(make_pair("だ", vector<string> {"da"}));
	hiragana.push_back(make_pair("ぢ", vector<string> {"di"}));
	hiragana.push_back(make_pair("づ", vector<string> {"du"}));
	hiragana.push_back(make_pair("で", vector<string> {"de"}));
	hiragana.push_back(make_pair("ど", vector<string> {"do"}));

	hiragana.push_back(make_pair("ば", vector<string> {"ba"}));
	hiragana.push_back(make_pair("び", vector<string> {"bi"}));
	hiragana.push_back(make_pair("ぶ", vector<string> {"bu"}));
	hiragana.push_back(make_pair("べ", vector<string> {"be"}));
	hiragana.push_back(make_pair("ぼ", vector<string> {"bo"}));

	hiragana.push_back(make_pair("ぱ", vector<string> {"pa"}));
	hiragana.push_back(make_pair("ぷ", vector<string> {"pu"}));
	hiragana.push_back(make_pair("ぴ", vector<string> {"pi"}));
	hiragana.push_back(make_pair("ぺ", vector<string> {"pe"}));
	hiragana.push_back(make_pair("ぽ", vector<string> {"po"}));

	hiragana.push_back(make_pair("ん", vector<string> {"n"}));
	
	hiragana.push_back(make_pair("じ", vector<string> {"zi", "ji"}));
	hiragana.push_back(make_pair("ち", vector<string> {"chi", "ti"}));
	hiragana.push_back(make_pair("し", vector<string> {"shi", "si"}));
	hiragana.push_back(make_pair("つ", vector<string> {"tsu", "tu"}));


	cout << "\n\nPractice Hiragana, type \"q\", \"quit\", or \"exit\" to quit, or \"help\" for a reference list. If you want to reveal the answer, type \"ans\"" << "\n" << "Ganbatte!\n\n";
	string in;
	while(in != "exit" && in != "quit" && in != "q")
	{
		bool is_correct = false;
		srand(time(NULL));
		int num = rand() % hiragana.size();
		cout << "\n" << hiragana[num].first << "\n\n";
		cin >> in;
		while(!is_correct)
		{
			if(in == "ans")
			{
				cout << "\nThe answer is: " << hiragana[num].first << " = ";
				for(int x = 0; x < hiragana[num].second.size(); ++x)
				{
					cout << hiragana[num].second[x];

					if(x != (hiragana[num].second.size() - 1))
					{
						cout << " or ";
					}
					else
					{
						cout << "\n\n";
					}
				}
				break;
			}
			else if(in == "help")
			{
				for(int i = 0; i < hiragana.size(); ++i)
				{
					cout << hiragana[i].first << " = ";

					for(int x = 0; x < hiragana[i].second.size(); ++x)
					{
						cout << hiragana[i].second[x];

						if(x != (hiragana[i].second.size() - 1))
						{
							cout << ", ";
						}
						else
						{
							cout << "		";
						}
					}
					if(i % 5 == 4)
					{
						cout << "\n";
					}
				}

				cout << "\n\nTry again\n\n" << hiragana[num].first << "\n\n";
				cin >> in;
			}
			else if(in == "exit" || in == "quit" || in == "q")
			{
				break;
			}
			else
			{
				for(int x = 0; x < hiragana[num].second.size(); ++x)
				{
					if(hiragana[num].second[x] == in)
					{
						is_correct = true;
						break;
					}
				}
				if(!is_correct)
				{
					inc(in, num);
				}
			}
		}
		if(in == "ans")
		{
			cout << "\nNext hiragana: \n";
		}
		else if(in != "exit" && in != "quit" && in != "q")
		{
			cout << "\n\nHai!\n\n";
		}
	}

	cout << "\nOtsukaresama deshita! Sayonara! Nyaaaa~\n\n";
}

void inc(string& input, int num)
{
	cout << "\nChigau, pls try again" << "\n\n";
	cout << "\n" << hiragana[num].first << "\n\n";
	cin >> input;
}
