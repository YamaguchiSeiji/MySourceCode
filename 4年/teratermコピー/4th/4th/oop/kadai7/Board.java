class Board {
	static int STONE_NUM = 9; // 石を置く枠の数
	static char CHAR_FREE = '.'; // 石が置かれていないときの文字
	static char[] CHAR_STONES = {'O', 'X'}; // プレイヤ 0の石とプレイヤ 1の石
	private int data[]; // ボード上の各マスに石が置かれているか．0:プレイヤ 0の石が置かれている，1:プレイヤ 1の石が置かれている，負の値:何も置かれていない．
	
	Board() {
		data = new int[STONE_NUM];
		for (int i = 0; i < STONE_NUM; i++)
			data[i] = -1; // データの初期値は何も置かれていない状態とする．
	}
	
	void show() {
		for(int i = 0; i < STONE_NUM; i++){
			if(data[i] != -1){
				System.out.print(CHAR_STONES[data[i]]);
			} else {
				System.out.print(CHAR_FREE);
			}
			if(i % 3 == 2){
				System.out.println();
			}
		}
	}

	boolean put(int locnum, int pnum) {
		if(data[locnum] == -1){
			data[locnum] = pnum;
			return true;
		} else {
			return false;
		}
	}

	int getStone(int locnum){
		return data[locnum];
	}

	boolean checkWin(int pnum) {
		int [][] locs = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}};
		boolean isWin = false;
		for(int[] loc: locs){
			for(int i = 0; i < 3; i++){
				if(data[loc[i]] == pnum){
					isWin = true;
				} else {
					isWin = false;
					break;
				}
			}
			if(isWin){
				return isWin;
			}
		}
		return false;
	}

	boolean checkDraw(){
		boolean isDraw = true;
		for(int i = 0; i <STONE_NUM; i++){
			if(data[i] == -1){
				isDraw = false;
				break;
			}
		}
		return isDraw;
	}

	void display(){
		String[][] display_Stones = {{
			"     *****     ",
			"    *     *    ",
			"   *       *   ",
			"   *       *   ",
			"   *       *   ",
			"    *     *    ",
			"     *****     ",
		}, {
			"    *     *    ",
			"     *   *     ",
			"      * *      ",
			"       *       ",
			"      * *      ",
			"     *   *     ",
			"    *     *    ",
		}};

		String[] display_Free = {
			"               ",
			"               ",
			"               ",
			"               ",
			"               ",
			"               ",
			"               ",
		};
		
		for(int i = 0; i < 3; i++){
			System.out.println("-------------------------------------------------");
			for(int j = 0; j < display_Free.length; j++){
				for(int k = 0; k < 3; k++){
					System.out.print("|");
					if(data[i * 3 + k] == -1){
						System.out.print(display_Free[j]);
					} else {
						System.out.print(display_Stones[data[i * 3 + k]][j]);
					}
					if(k == 2){
						System.out.println("|");
					}
				}
			}
			if(i == 2){
				System.out.println("-------------------------------------------------");
			}
		}
	}
}

