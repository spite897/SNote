# buildLog
- program: **lua_basis_1** 
- from: **runoob** 
- status: **done** 

-----------------------------------------------------------------------------

### 基本語法

```lua
#!/usr/local/bin/lua
-- 指定解釋器 用於快捷執行腳本

print("Hello World")

--[=[ 
-- 改爲三連 - 符號可以用於啓用/禁用多行註釋中的代碼

multi statement

--]=]
```

> 一般約定 下劃線UPS 被保留用於Lua內部全局變量

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

### 數據類型

| type     | desc              |
| -        | -                 |
| nil      | 未定義；值爲false |
| boolean  |                   |
| number   | double            |
| string   | '' or "" or [[]]  |
| function | C or Lua function |
| userdata | C 數據結構        |
| thread   |                   |
| table    |                   |

> type() 用於返回一個變量類型的 string   
 
**關於 boolean** 
- { nil, false } => false  ;  0=>true


**關於 string**
- 使用 .. 鏈接字符串
- 字符串+-運算會轉換爲number類型
- 使用 # 獲得字符串長度
- 使用 [[]] 創造跨行字符

關於 table
- 索引從1開始
- 解除所有引用後 lua垃圾回收會釋放內存
- `gettable_evnet(table, index)`

關於賦值
- 允許多個變量同時賦值 先計算結果再進行賦值

```lua
function <function_name>( <args> )
    <statement>
end
```

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

### Table操作

| func                                       | desc                                                                   |
| -                                          | -                                                                      |
| table.concat(table[, sep[, start[, end]]]) | 將 Table 數組部分指定位置元素連接成字符串並返回 以sep爲間隔 缺省sep="" |
| table.insert(table,[pos,] value)           | 缺省pos=-1                                                             |
| table.remove(table[, pos])                 | 返回並刪除 缺省pos=-1                                                  |
| table.sort(table[, comp])                  | 缺省升序排列                                                           |

> `concatenate` 
 
-----------------------------------------------------------------------------
