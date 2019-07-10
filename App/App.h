#include "SelectWindow.h"
#include "EditWindow.h"
#include "EditorViewModel.h"

class Mota
{
public:
	Mota();
	~Mota() throw();

	bool Init();
	void Show();

private:
	EditWindow  editWindow;
	SelectWindow selectWindow;
	std::shared_ptr<EditorViewModel>  editViewModel;
};
