# buildLog
- program: **lua_basis_4** 
- from: **runoob** 
- status: **building** 

=================================所謂協同====================================

子集於線程，主要區別在於不能同時運行多個線程，需要彼此協作運行。

| func                   | desc                                       |
| -                      | -                                          |
| create( func )         | 創建並返回協同                             |
| resume( crot, [args] ) | 重啓協同 以及傳遞參數                      |
| yield( msg )           | 掛起協同 對外返回msg 對內返回接收數據      |
| status()               | 查看協同狀態(dead,  suspended, running )   |
| wrap( func )           | 創建並將協同打成函數                       |
| running()              | 返回正在運行的coroutine                    |

### 關於 yield 與 resume 參數的傳遞

```lua
local CROT = coroutine.create( function( a )
    local recv = yield("Y_MSG")
    return a , recv
end)

coroutine.resume(CROT, "R_MSG1")
-- 返回 true, "Y_MSG"
coroutine.resume(CROT, "R_MSG2")
-- 返回 true, "R_MSG1", "R_MSG2"
coroutine.resume(CROT)
-- 返回 false, "cannot resume dead coroutine"
```

-----------------------------------------------------------------------------
