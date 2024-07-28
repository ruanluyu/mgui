#pragma once

#include "basic.h"

namespace mgui {
	extern class UUIDObject;
	using sobj = sptr<UUIDObject>;
	using wobj = wptr<UUIDObject>;

	struct UUIDObjectHasher {
		size_t operator()(const mgui::UUIDObject& instance) const;
		size_t operator()(const sobj& instance) const;
	};
	struct UUIDObjectComparer {
		size_t operator()(const mgui::UUIDObject& l, const mgui::UUIDObject& r) const;
		size_t operator()(const sobj& l, const sobj& r) const;
	};


	enum UUIDObjectEvent {
		CUSTOM_EVENT_ID_START = 0x00000000u,

		CUSTOM_EVENT_ID_END = 0x0fffffffu,

		RESERVED_EVENT_ID_START = 0x10000000u,
		AFTER_CREATED = RESERVED_EVENT_ID_START,
		BEFORE_FINALIZED,
		RESERVED_EVENT_ID_END = 0x1fffffffu,
	};

	class UUIDObject
	{
	public:
		using ChildrenContainer = std::unordered_set<sobj, UUIDObjectHasher, UUIDObjectComparer>;
	private:
		UUIDKey uuid;
		std::string name;
		sobj self;
		sobj parent;
		ChildrenContainer children;
	public:
		UUIDObject();
		~UUIDObject();

		virtual const UUIDKey& GetUUID() const;

		virtual void SetName(const std::string& new_name);

		virtual const std::string& GetName() const;

		virtual sobj GetSelf() const;

		virtual void SetParent(const sobj& new_parent);

		virtual sobj GetParent() const;

		virtual void ClearChildren();

		virtual const ChildrenContainer& GetChildren() const;

		virtual void HandleEvent(UUIDObjectEvent event_id, void* argument = nullptr);

		template<typename T>
		static sobj Create()
		{
			auto objptr = std::dynamic_pointer_cast<UUIDObject>(std::make_shared<T>());
			objptr->self = objptr;
			objptr->HandleEvent(AFTER_CREATED);
			return objptr;
		}

		static void Finalize(const sobj& objptr);

		bool operator==(const UUIDObject& other) const;
	};


}



