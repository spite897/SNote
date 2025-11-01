# buildLog
- program: **github_connection_steampp_solution**
- status: **done**

-----------------------------------------------------------------------------

> 關於鏈接github的問題 最初因爲時有時無的牆及我較低的訪問需求擱置許久 最近在 
> 使用paru安裝包時無法鏈接github導致失敗 因而尋找此解決方案

-----------------------------------------------------------------------------

#### steampp

```terminal
$ paru -S watt-toolkit
```

> 注意可以選用 gitee 源下載

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#### 關於 Certificate

steampp會爲你提供一個瀏覽器訪問的解決方案 即添加其的crt到瀏覽器信任名單
- `.local/share/Steam++/Plugins/Accelerator`

#### Addition

> 我在使用時還發現curl會因爲証書問題無法訪問 解決方法同上 如下細則

```terminal
$ sudo trust anchor --store SteamTools.Certificate.crt
```

> .crt 與 .cer 爲同類型文件 直接修改後綴名轉換即可

-----------------------------------------------------------------------------
