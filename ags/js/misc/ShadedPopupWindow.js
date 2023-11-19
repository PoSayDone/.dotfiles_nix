import App from 'resource:///com/github/Aylur/ags/app.js';
import Widget from 'resource:///com/github/Aylur/ags/widget.js';

/** @param {string} windowName */
const Padding = windowName => Widget.EventBox({
    class_name: 'padding',
    hexpand: true,
    vexpand: true,
    connections: [['button-press-event', () => App.toggleWindow(windowName)]],
});

/**
 * @param {import('types/widgets/window').WindowProps & {
 *      name: string
 *      child: import('types/widgets/box').default
 *  }} o
 */
export default ({ name, child, ...rest }) => Widget.Window({
    ...rest,
    class_names: ['popup-window', name],
    name,
    visible: false,
    popup: true,
    focusable: true,
    setup() {
        child.toggleClassName('window-content');
    },
    child: Widget.CenterBox({
        class_name: 'scrim',
        css: 'min-width: 2000px; min-height: 1200px;',
        children: [
            Padding(name),
            Widget.CenterBox({
                vertical: true,
                children: [
                    Padding(name),
                    child,
                    Padding(name),
                ],
            }),
            Padding(name),
        ],
    }),
});
