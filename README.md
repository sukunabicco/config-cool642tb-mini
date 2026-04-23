# cool642tb-mini ZMK Firmware

cool642tb-mini 分割キーボード用のZMKファームウェア設定リポジトリです。

## 謝辞

このリポジトリは [na-ka-no/zmk-config-cool642tb-mini](https://github.com/na-ka-no/zmk-config-cool642tb-mini) をforkして作成しました。
オリジナルのキーボード設計およびファームウェアを公開してくださった [na-ka-no](https://github.com/na-ka-no) 様に感謝いたします。

## 概要

- **マイコン**: Seeeduino XIAO BLE（ZMK ボード名 `xiao_ble/nrf52840/zmk`、HWMv2）
- **トラックボール**: PMW3610（右手側）
- **接続**: Bluetooth (BLE)、右手側が central
- **日本語配列**: JIS配列対応
- **電源**: 単4電池 × 4本
- **ZMK**: [cormoran/zmk `main+dya`](https://github.com/cormoran/zmk/tree/main%2Bdya)（Zephyr 4.1 ベース）

## ビルド

GitHub Actionsにより自動ビルドされます。`main`ブランチへのpushまたはPull Requestで実行されます。

ビルド成果物:
- `cool642tb-mini_L-xiao_ble_nrf52840_zmk-zmk.uf2` - 左手側
- `cool642tb-mini_R-xiao_ble_nrf52840_zmk-zmk.uf2` - 右手側（トラックボール付き）
- `settings_reset-xiao_ble_nrf52840_zmk-zmk.uf2` - Bluetooth設定リセット用

## レイヤー構成

| レイヤー | 説明 |
|----------|------|
| layer0 | DEFAULT - 基本QWERTY配列 |
| layer1 | FUNCTION - 記号キー（JIS配列対応） |
| layer2 | NUM - 数字・ファンクションキー |
| layer3 | ARROW - 矢印・ナビゲーション |
| layer4 | MOUSE - マウス操作 |
| layer5 | SCROLL - スクロール操作 |
| layer6 | BLUETOOTH - BT接続管理 |

## ファイル構成

```
config/
├── cool642tb-mini.keymap    # キーマップ定義
├── cool642tb-mini.json      # レイアウト定義
├── locale/
│   └── keys_ja.h            # 日本語(JIS)キー定義
├── boards/shields/Test/     # シールド設定
│   ├── cool642tb-mini.dtsi
│   ├── cool642tb-mini_L.conf
│   ├── cool642tb-mini_L.overlay
│   ├── cool642tb-mini_R.conf
│   └── cool642tb-mini_R.overlay
└── west.yml                 # 依存関係定義
```

## ファームウェア書き込み

1. Seeeduino XIAO BLEをブートローダーモードにする（リセットボタン2回押し）
2. マウントされたドライブに`.uf2`ファイルをコピー
3. 自動的に再起動してファームウェアが適用される

### 大きな構成変更を反映する場合（例: HWMv1 → HWMv2、ZMK メジャー更新）

settings の互換性が切れていることがあるので以下の順で書き込む:

1. L・R 両方に `settings_reset-...uf2` を書き込む
2. L に `cool642tb-mini_L-...uf2` を書き込む
3. R に `cool642tb-mini_R-...uf2` を書き込む
4. PC との BT ペアリングをやり直す

## DYA Studio での接続

ブラウザ上でキーマップを編集できる [DYA Studio](https://studio.dya.cormoran.works/) に対応しています。

### 接続手順

1. **右手側（central）** を USB ケーブルで PC に直結する
2. Chrome / Edge / Arc など [Web Serial API](https://developer.mozilla.org/docs/Web/API/Web_Serial_API) 対応ブラウザで <https://studio.dya.cormoran.works/> を開く（Firefox / Safari は非対応）
3. 「接続」→ シリアルポート一覧から右手側を選択
4. `&studio_unlock` キーを押してロック解除（下記参照）
5. キーマップ編集 / バッテリー履歴確認 → 保存で右手側に書き込み

### 有効になっている DYA 拡張

| 機能 | 状態 | 備考 |
|---|---|---|
| ZMK Studio（キーマップ編集） | ✅ | |
| Battery History | ✅ | Studio からバッテリ履歴確認可 |
| Settings RPC | ✅ | |
| BLE Management（Studio 上のペアリング UI） | ❌ | `zmk-module-ble-management` が ZMK main API 変更（`zmk_endpoint_*_preferred_transport` への rename）に未追従のため。通常の BT キー（`&bt BT_SEL ...`）で代用可 |
| Runtime Input Processor（Studio 上の感度調整） | ❌ | `zmk-module-runtime-input-processor` が `zmk_keymap_layer_activate` の引数変更に未追従のため。感度は DT の `res-cpi` / `zip_scroll_scaler` で固定 |

### unlock キーの位置

`&studio_unlock` は **layer6 の左手最上段・左端**（layer0 で `Q` がある物理位置）に配置されています。

操作手順:

1. layer0 で **左手親指クラスタ左から 2 番目のキー（`lt 6 ESCAPE`）を長押し** → layer6 に入る
2. その状態で **左手最上段の左端キー** を押す → ロック解除

## 主な変更履歴

### 2026-04-23 - cormoran `main+dya` への移行（Zephyr 4.1）

- ZMK: `cormoran/v0.3-branch+dya`（Zephyr 3.5）→ `cormoran/main+dya`（Zephyr 4.1）
- ボード名: `seeeduino_xiao_ble`（HWMv1）→ `xiao_ble/nrf52840/zmk`（HWMv2）
- PMW3610 ドライバ: `badjeff/zmk-pmw3610-driver` → Zephyr 同梱ドライバ（`zephyr/drivers/input/input_pmw3610.c`）。Kconfig 名も `CONFIG_PMW3610` → `CONFIG_INPUT_PMW3610`、DT プロパティも `irq-gpios`/`x-input-code`/`cpi` → `motion-gpios`/`zephyr,axis-x`/`res-cpi` に変更
- Prospector モジュール: `t-ogura` v2.0.0 → v2.2b（Zephyr 4.x 対応）
- Workflow: `cormoran/zmk@v0.3-branch+dya` → `cormoran/zmk@main+dya`（HWMv2 のスラッシュ入りボード名を `cp` できるよう更新済みの reusable workflow を使う）
- 背景: feature/scanner 時代（ZMK main + HWMv2）は XIAO BLE ボード DTS 側に vbatt ノードが含まれていてバッテリ残量を計測できていた。cormoran v0.3 fork + HWMv1 環境では shield 側で vbatt を自前定義しても 0% しか読めず、同じ条件を再現するため main+dya へ移行した
- 代償: `zmk-module-ble-management` と `zmk-module-runtime-input-processor` は ZMK main API 変更に追従できておらず、一時的に drop（上記「有効になっている DYA 拡張」参照）

## 参考

- [cool642tb-mini 使い方ガイド](https://note.com/na__ka__no/n/n6d4a7c7ecf30)
- [cool642tb-mini - BOOTH](https://nakanoo.booth.pm/items/7464429)
- [ZMK Firmware](https://zmk.dev/)
- [cormoran/zmk (main+dya)](https://github.com/cormoran/zmk/tree/main%2Bdya) - DYA Studio 対応フォーク
- [DYA Studio](https://studio.dya.cormoran.works/)
- [Zephyr PMW3610 driver](https://github.com/zephyrproject-rtos/zephyr/blob/main/drivers/input/input_pmw3610.c)
