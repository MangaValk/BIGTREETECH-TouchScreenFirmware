#include "Leveling.h"
#include "includes.h"

//1��title(����), ITEM_PER_PAGE��item(ͼ��+��ǩ)
const MENUITEMS levelingItems = {
    //   title
    LABEL_READY,
    // icon                       label
    {
        {ICON_LEVEL_Z, LABEL_LEVEL_Z},
        {ICON_HEAT, LABEL_HEAT},
        {ICON_LEVEL_3_POINT, LABEL_LEVEL_3_POINT},
        {ICON_LEVEL_CLEAR, LABEL_LEVEL_CLEAR},
        {ICON_LEVEL_PROBE, LABEL_LEVEL_PROBE},
        {ICON_LEVEL_FILL_BLANKS, LABEL_LEVEL_FILL_BLANKS},
        {ICON_LEVEL_SAVE, LABEL_LEVEL_SAVE},
        {ICON_BACK, LABEL_BACK},
    }};

void menuLeveling(void)
{
  KEY_VALUES key_num = KEY_IDLE;

  menuDrawPage(&levelingItems);

  while (infoMenu.menu[infoMenu.cur] == menuLeveling)
  {
    key_num = menuKeyGetValue();
    switch (key_num)
    {
    case KEY_ICON_0: // G28 or G34?
      storeCmd("G28\n");
      storeCmd("G34\n");
      break;
    case KEY_ICON_1:
      storeCmd("M140 S50\n");
      break;
    case KEY_ICON_2:
      storeCmd("G29 J\n");
      break;
    case KEY_ICON_3:
      storeCmd("G29 P0\n");
      break;
    case KEY_ICON_4:
      storeCmd("G29 P1\n");
      break;
    case KEY_ICON_5:
      storeCmd("G29 P3\n");
      break;
    case KEY_ICON_6:
      storeCmd("G29 S\n");
      break;
    case KEY_ICON_7:
      infoMenu.menu[++infoMenu.cur] = menuMain;
      break;
    default:
      break;
    }
    loopProcess();
  }
}
