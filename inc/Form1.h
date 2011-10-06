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

#ifndef _FORM1_H_
#define _FORM1_H_

#include <FBase.h>
#include <FUi.h>
#include <FGraphics.h>
#include <FApp.h>

class Form1 : public Osp::Ui::Controls::Form,
        public Osp::Ui::Controls::IListViewItemEventListener,
        public Osp::Ui::Controls::IListViewItemProvider {

        // Construction
    public:
        Form1(void);
        virtual ~Form1(void);
        bool Initialize(void);

        static const int ID_FORMAT_STRING = 100;
        static const int ID_FORMAT_BITMAP = 101;
        static const int ID_CONTEXT_ITEM_1 = 102;
        static const int ID_CONTEXT_ITEM_2 = 103;

        // Implementation
    protected:
        Osp::Ui::Controls::ListView *pListView;

    public:
        virtual result OnInitializing(void);
        virtual result OnTerminating(void);

        // IListViewItemEventListener
        virtual void
        OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView,
                                                 int itemIndex,
                                                 int elementId,
                                                 Osp::Ui::Controls::ListContextItemStatus state);
        virtual void
        OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView,
                                          int itemIndex,
                                          int elementId,
                                          Osp::Ui::Controls::ListItemStatus state);

        virtual void OnListViewItemSwept(Osp::Ui::Controls::ListView &listView,
                                                int itemIndex,
                                                Osp::Ui::Controls::SweepDirection direction);

        virtual void OnListViewItemLongPressed(Osp::Ui::Controls::ListView & listView,
                                                      int  itemIndex,
                                                      int  elementId,
                                                      bool & invokeListViewItemCallback);

        // IListViewItemProvider
        virtual int GetItemCount();
        virtual Osp::Ui::Controls::ListItemBase* CreateItem(int itemIndex,
                                                            int itemWidth);
        virtual bool DeleteItem(int itemIndex,
                                Osp::Ui::Controls::ListItemBase* pItem,
                                int itemWidth);

};

#endif	//_FORM1_H_
