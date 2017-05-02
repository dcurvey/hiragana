#include <iostream>
#include <string>
#include <tuple>
#include <stdlib.h>
#include <utility> 
#include <vector>
#include <ctime>

using namespace std;

void init();
void inc(string&, int);
void help(string&, int);
void ans(int);
int rand_func(int);

vector<pair<string, vector<string>>> hiragana{};
vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70};
int num = 0;

int main(int argc, char** argv)
{
	srand(time(NULL));
	init();

	int num_correct = 0;
	int num_first = 0;
	string in;
	while(in != "exit" && in != "quit" && in != "q")
	{
		bool is_correct = false;
		bool used_help = false;
		bool first_try = true;
				
		cout << "\n" << hiragana[nums[num]].first << "\n\n";
		cin >> in;
		
		while(!is_correct)
		{
			if(in == "ans")
			{
				ans(nums[num]);
				used_help = true;
				break;
			}
			else if(in == "help")
			{
				help(in, nums[num]);
				used_help = true;
			}
			else if(in == "exit" || in == "quit" || in == "q")
			{
				break;
			}
			else
			{
				for(int x = 0; x < hiragana[nums[num]].second.size(); ++x)
				{
					if(hiragana[nums[num]].second[x] == in)
					{
						is_correct = true;
						if(!used_help)
						{
							num_correct++;
							if(first_try)
							{
								num_first++;
							}
						}
						break;
					}
				}
				if(!is_correct)
				{
					inc(in, nums[num]);
					if(first_try)
					{
						first_try = false;
					}
				}
			}
		}
		if(in != "exit" && in != "quit" && in != "q" && in != "ans")
		{
			cout << "\n\nHai!\n";
		}

		num++;
		if(num == hiragana.size())
		{
			cout << "Omedetou gozaimasu! You made it through all 71 hiragana!\nYou got " << num_correct << "/71 correct without help, and " << num_first << "/71 on your first try.\n\nRe-shuffling the list...\n";
			num = 0;
			num_correct = 0;
			num_first = 0;

			srand(time(NULL));
			random_shuffle(nums.begin(), nums.end(), rand_func);
		}

		cout << "\nNext hiragana: \n";
	}

	cout << "\nOtsukaresama deshita! Sayonara! Nyaaaa~\n\n";
}

void init()
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

	cout << "\n\nPractice Hiragana! type \"q\", \"quit\", or \"exit\" to quit, or \"help\" for a reference list. If you want to reveal the answer, type \"ans\"" << "\n" << "Ganbatte!\n\n";

	random_shuffle(nums.begin(), nums.end(), rand_func);
}

void inc(string& input, int num)
{
	cout << "\nChigau, pls try again" << "\n\n";
	cout << "\n" << hiragana[num].first << "\n\n";
	cin >> input;
}

void help(string& input, int num)
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
	cin >> input;
}

void ans(int num)
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
}

int rand_func(int x)
{
	return ((int)rand() % x);
}