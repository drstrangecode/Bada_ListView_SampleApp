 /*
 * Created by: Dr. Strangecode
 * ---------------------------------------------
 * This is free code, it can be used, modified,
 * destroyed, raped and whatever without limits.
 * I own no copyrights over it.
 * This code is provided AS IS without warranty
 * of any kind either expressed or implied,
 * including but not limited to the implied
 * warranties of merchantability and/or fitness
 * for a particular purpose.
 * ---------------------------------------------
 * For more free code visit http://drstrangecode.org
 */

#include "Form1.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::App;

Form1::Form1(void) {
}

Form1::~Form1(void) {
}

bool Form1::Initialize() {
    // Construct an XML form
    Construct(L"IDF_FORM1");

    return true;
}

result Form1::OnInitializing(void) {
    result r = E_SUCCESS;

    pListView = static_cast<ListView *> (GetControl(L"IDC_LISTVIEW"));
    pListView->SetItemProvider(*this);
    pListView->AddListViewItemEventListener(*this);
    pListView->SetSweepEnabled(false);

    return r;
}

result Form1::OnTerminating(void) {
    result r = E_SUCCESS;

    return r;
}

// IListViewItemEventListener
void Form1::OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView,
                                              int itemIndex,
                                              int elementId,
                                              Osp::Ui::Controls::ListContextItemStatus state) {

	AppLog("OnListViewContextItemStateChanged() : Item: %d", itemIndex);
}

void Form1::OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView,
                                       int itemIndex,
                                       int elementId,
                                       Osp::Ui::Controls::ListItemStatus state) {

	AppLog("OnListViewItemStateChanged() : Item: %d", itemIndex);
	switch (state) {
		case LIST_ITEM_STATUS_CHECKED:
			AppLog("LIST_ITEM_STATUS_CHECKED");
		break;
		case LIST_ITEM_STATUS_HIGHLIGHTED:
			AppLog("LIST_ITEM_STATUS_HIGHLIGHTED");
		break;
		case LIST_ITEM_STATUS_MORE:
			AppLog("LIST_ITEM_STATUS_MORE");
		break;
		case LIST_ITEM_STATUS_SELECTED:
			AppLog("LIST_ITEM_STATUS_SELECTED");
		break;
		case LIST_ITEM_STATUS_UNCHECKED:
			AppLog("LIST_ITEM_STATUS_UNCHECKED");
		break;
	}
}

void Form1::OnListViewItemSwept(Osp::Ui::Controls::ListView &listView,
                                int itemIndex,
                                Osp::Ui::Controls::SweepDirection direction) {

	AppLog("OnListViewItemSwept() : Item: %d", itemIndex);
	switch (direction) {
	case SWEEP_DIRECTION_LEFT:
		AppLog("SWEEP_DIRECTION_LEFT");
	break;
	case SWEEP_DIRECTION_RIGHT:
		AppLog("SWEEP_DIRECTION_RIGHT");
	break;
	}
}

void Form1::OnListViewItemLongPressed(Osp::Ui::Controls::ListView & listView,
                                             int  itemIndex,
                                             int  elementId,
                                             bool & invokeListViewItemCallback) {

	AppLog("OnListViewItemLongPressed() : Item: %d", itemIndex);

}

// IListViewItemProvider
int Form1::GetItemCount() {
    return 3;
}

Osp::Ui::Controls::ListItemBase* Form1::CreateItem(int itemIndex, int itemWidth) {

    String text;
    text.Format(100, L"SimpleItem #%d", itemIndex);

	AppResource * res = Application::GetInstance()->GetAppResource();
	Bitmap * pBitmap = res->GetBitmapN(L"itemicon.png",
			                           BITMAP_PIXEL_FORMAT_ARGB8888);

	SimpleItem * pItem = new SimpleItem();

	pItem->Construct(Dimension(itemWidth, 100), LIST_ANNEX_STYLE_DETAILED);
	pItem->SetElement(text, pBitmap);

	ListContextItem* pItemContext = new ListContextItem();
	pItemContext->Construct();
	pItemContext->AddElement(0, "Call");
	pItemContext->AddElement(1, "Send SMS");
	pItemContext->AddElement(2, "Send e-mail");

	pItem->SetContextItem(pItemContext);

	delete pBitmap;

    return pItem;

}

bool Form1::DeleteItem(int itemIndex,
                       Osp::Ui::Controls::ListItemBase* pItem,
                       int itemWidth) {
	/* pItem is not deleted here */
	return false;
}
