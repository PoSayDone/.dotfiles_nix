import PopupWindow from '../misc/PopupWindow.js';
import { Widget } from '../imports.js';

export default () => PopupWindow({
    name: 'calendar',
	anchor: ['top'],
    child: Widget.Box({
        class_name: 'calendar',
        children: [
            Widget.Calendar({
                hexpand: true,
                hpack: 'center',
            }),
        ],
    }),
});
