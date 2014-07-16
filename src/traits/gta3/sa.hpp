/* 
 * Copyright (C) 2014  LINK/2012 <dma_2012@hotmail.com>
 * Licensed under GNU GPL v3, see LICENSE at top level directory.
 * 
 *  Most of things game version dependent (not being addressed by the addr translator) should be handled by the game trait
 *
 */
#pragma once
#include "base.hpp"

struct TraitsSA : TraitsGTA
{
    // Pools
    using VehiclePool_t     = CPool<typename std::aligned_storage<0xA18, 1>::type>;
    using PedPool_t         = CPool<typename std::aligned_storage<0x7C4, 1>::type>;
    using ObjectPool_t      = CPool<typename std::aligned_storage<0x19C, 1>::type>;
    using BuildingPool_t    = CPool<typename std::aligned_storage<0x38, 1>::type>;
    using DummyPool_t       = CPool<typename std::aligned_storage<0x38, 1>::type>;

    // Indices range
    const id_t  dff_start   = 0;
    const id_t& txd_start   = injector::lazy_object<0x5B62CF, uint32_t>::get();
    const id_t& max_models  = txd_start;
    const id_t& dff_end     = txd_start;

    // Type of entities
    enum class EntityType : uint8_t
    {
        Nothing,  Building, Vehicle, Ped, Object, Dummy, NotInPools
    };

    // Type of models
    enum class ModelType : uint8_t
    {
        Atomic = 1, DamageAtomic = 1, Time = 3, Lodtime = 3,
        Weapon = 4, Clump = 5, Vehicle = 6, Ped = 7, LodAtomic = 8
    };



    // Gets the entity model id
    static id_t GetEntityModel(void* entity)
    {
        return ReadOffset<uint16_t>(entity, 0x22);
    }

    // Gets the entity type
    static EntityType GetEntityType(void* entity)
    {
        return EntityType(ReadOffset<uint8_t>(entity, 0x36) & 0x7);
    }

    // Gets the entity RwObject pointer
    static void* GetEntityRwObject(void* entity)
    {
        return ReadOffset<void*>(entity, 0x18);
    }

    // Gets the ped intelligence pointer from a ped entity
    static void*& GetPedIntelligence(void* entity)
    {
        return ReadOffset<void*>(entity, 0x47C);
    }

    // Gets the ped task manaager pointer from a ped entity
    static void* GetPedTaskManager(void* entity)
    {
        return (char*)(GetPedIntelligence(entity)) + 0x4;
    }



    // Gets the model information structure from it's id
    static void* GetModelInfo(id_t id)
    {
        auto& p = injector::lazy_object<0x408897, void**>::get();
        return p[id];
    }

    // Gets the model type (Building, Ped, Vehicle, etc) from the model id
    static ModelType GetModelType(id_t id)
    {
        auto m = GetModelInfo(id);
        return ModelType(injector::thiscall<uint8_t(void*)>::vtbl<4>(m));
    }

    // Gets the model id tex dictionary index
    static id_t GetModelTxdIndex(id_t id)
    {
        if(auto m = GetModelInfo(id)) return ReadOffset<uint16_t>(m, 0x0A);
        return -1;
    }

    // Gets the usage count of the specified model id
    static int GetModelUsageCount(id_t id)
    {
        if(auto m = GetModelInfo(id)) return ReadOffset<uint16_t>(m, 0x08);
        return 0;
    }
};
