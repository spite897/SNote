# buildLog
- program: **plasma_colemak_solution**
- status: **done**

-----------------------------------------------------------------------------

Plasma桌面環境設置`Settings>Keyboard>Keyboard>Layouts_Add`，可以通過設置來實現用戶範圍的colemak映射。

> **注意**：使用虛擬鍵盤時，需要在其設置中更改。

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

實現plasma下可自定義的鍵盤映射可通過AUR `evremap` 包實現

```toml
#/etc/evremap.toml
device_name = ...
[[remap]]
input = [...]
output = [...]
```

啓用evremap

`$ sudo systemctl enable evremapw.service`

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

> tty下的 colemak 實現方法
>
> ```conf
> #/etc/vconsole.conf
> KEYMAP = colemak
> ```

-----------------------------------------------------------------------------
