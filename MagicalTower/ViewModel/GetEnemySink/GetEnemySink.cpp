#include<algorithm>
#include  "GameViewModel.h"

bool sortFun(const int& a, const int& b) {
	return a < b;
}

std::vector<int> GetEnemySink::onGetIntList() {
	vector<int> ve;
	ve.resize(121);
	ve.clear();
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 11; j++)
			if (m_gVM->gm->getSquareType(i, j) == 1)
				ve.push_back(m_gVM->gm->getSquareIndex(i, j));
	sort(ve.begin(), ve.end(), sortFun);
	vector<int> re(25);
	re.clear();
	int h = -1;
	for (int i : ve)
		if (h < 0 || i != re[h]) {
			re.push_back(i);
			h++;
		}
	return re;
}