#ifndef KPLAYER_PLUGIN_CONFIG_H
#define KPLAYER_PLUGIN_CONFIG_H


#define KPLAYER_VERSION_PLUGIN "1.0.2"

#define KPLAYER_PLUGIN_FUNC(x) __attribute__ ((visibility ("default"))) x *CreateInstance(PluginParams params)

extern "C" {
    __attribute__ ((visibility ("default"))) const char* GetPluginVersion(){
        return KPLAYER_VERSION_PLUGIN;
    }
}

#endif //KPLAYER_PLUGIN_CONFIG_H

