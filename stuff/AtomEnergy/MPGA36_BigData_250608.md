# PLog
- father: **AtomEnergy/MPGA** 
- status: **done** 

-----------------------------------------------------------------------------

### P0: opening

- Big data was hot in 2010s.
- Author , a programmer played at that time.
- Brief words: Big data -> A misjudge of tech developping direction by mans.

-----------------------------------------------------------------------------

### P1: 開端到謝幕

CD20 互聯網泡沫破裂 搜索引擎 電商 社交網絡興起 
-(cause)> data progress over computing ability -> Big data's birth
-(promote)> google facebook 's action

計算機算力不會超過線性增長[^1] -> Scale-up Scale-out 分佈式計算的大數據框架

Prediction 1 : Data gonna progrss exponentially

the realistic progress
![250608_growingSpeed](/imgs/AtomEnergy_MPGA/250608_growingSpeed.png)

-----------------------------------------------------------------------------

### P2: 數據增長低於預期

04 MapReduce Issue from Google
作爲龐大的搜索引擎公司，google的論文是誤導大數據發展方向的重大因素。
BigQuery （Google） 的活躍用戶裏數據儲存量中位數不足100GB
Gartner Forrester ，市場分析組織，大多數企業的數據倉庫體量只有百GB量級

噪音數據多，前期盲目階段，無法擇出有效信息而進行全盤記錄。

e.g. : 國際象棋比賽的數據統計： 7個節點的hadoop集羣 computing took 26 mins.
    直接讀進內存計算 僅用時12s
    
-----------------------------------------------------------------------------

### P3: 算力增長正常進行
儲存量與計算量增長不對㩐
算力發展，決策週期縮短，數據廢棄速度快

BigQuery : 90%查詢所調用數據不足100mb
        一個月就能迭代一輪數據

-----------------------------------------------------------------------------

### P4: 實用層面的錯誤

大數據模型的主要功能是參與決策制定
- 人力決策的衝突： 人的決策蓋過大數據決策，數據驅動權利架空
- 分析模式的缺陷： 現實世界是混沌系統，數據決策不能完全信賴
人類對數據驅動的業務模式信心不足

-----------------------------------------------------------------------------


[^1]: 存在爭議 
