#include "GameModel.h"
#include "GetSpeIntSink.h"
#include "MoveSink.h"
#include "gSetNameSink.h"
#include "gGetSquare.h"

class GameViewModel {
public:
	shared_ptr<GetSpeSink> m_gssink;
	shared_ptr<MoveSink> m_mvsink;
	shared_ptr<gSetNameSink> m_gsnink;
	shared_ptr<gGetSquareTSink> m_gstink;
	shared_ptr<gGetSquareISink> m_gsiink;
	shared_ptr<GameModel> gm;
	GameViewModel();
	bool saveGame(std::string name);
	bool loadGame(std::string path, std::string name);
	int move(int direction) { return gm->Move(direction); }
};