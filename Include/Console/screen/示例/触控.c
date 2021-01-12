#include "../screen.h"

int main()
{
	C4S_Suite suite;
	char str[80] = {};
	int count;
	int value;
	int num;
	
	C4S_Init();
	
	C4S_CloseInputEcho();
	C4S_OpenTouchEcho();
	
	while (1)
	{
		if (count = C4S_Input(str, 80, 0, 0))
		{
			value = 0;
			
			while (num = C4S_SplitSuite(str + value, count - value, &suite))
			{
				value += num;
				
				switch (suite.type)
				{
					case C4S_SUITE_CHUCK:
						if (suite.chuck.state == C4S_CHUCK_PRESSED)
							printf("按下:");
						else
							printf("弹起:");
						printf("(%d,%d)\n", suite.chuck.x, suite.chuck.y);
						break;
						
					case C4S_SUITE_SCROLL:
						if (suite.scroll.direction == C4S_SCROLL_UP)
							printf("上滚:");
						else
							printf("下滚:");
						printf("(%d,%d)\n", suite.scroll.x, suite.scroll.y);
						break;
						
					default:
						break;
				}
			}
		}
	}
	
	C4S_Quit();
}