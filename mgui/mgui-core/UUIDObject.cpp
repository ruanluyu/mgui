#include "pch.h"
#include "UUIDObject.h"


namespace mgui {
	sobj UUIDObject::GetSelf() const
	{
		return self;
	}
	void UUIDObject::SetName(const std::string& name)
	{
		this->name = name;
	}

	const std::string& UUIDObject::GetName() const
	{
		return name;
	}

	const UUIDObject::ChildrenContainer& UUIDObject::GetChildren() const
	{
		return children;
	}

	void UUIDObject::ClearChildren()
	{
		for (auto& child : children)
		{
			child->SetParent(nullptr);
		}
		children.clear();
	}
	const UUIDKey& UUIDObject::GetUUID() const
	{
		return uuid;
	}
	void UUIDObject::SetParent(const sobj& new_parent)
	{
		if (parent == new_parent) return;
		if (parent)
		{
			parent->children.erase(self);
		}
		parent = new_parent;
		if (new_parent)
		{
			new_parent->children.insert(self);
		}
	}
	sobj UUIDObject::GetParent() const
	{
		return parent;
	}

	UUIDObject::UUIDObject()
		: uuid(UUIDKey::Generate())
		, name()
		, self()
		, parent()
		, children()
	{
	}
	UUIDObject::~UUIDObject()
	{
		std::stringstream ss;
		ss << "Finalized: " << uuid.ToString() << name << std::endl;
		Log(ss.str(), LOGLV_INFO);
	}
	size_t UUIDObjectHasher::operator()(const mgui::UUIDObject& instance) const
	{
		return instance.GetUUID().GetHashCode();
	}
	size_t UUIDObjectHasher::operator()(const sobj& instance) const
	{
		if (!instance) return UUIDKey::GenerateZeroed().GetHashCode();
		return instance->GetUUID().GetHashCode();
	}

	void UUIDObject::HandleEvent(UUIDObjectEvent event_id, void* argument) 
	{
		switch (event_id)
		{
		case mgui::BEFORE_FINALIZED:
		{
			parent.reset();
			for (auto& child : children)
			{
				Finalize(child);
			}
			children.clear();
		}
			break;
		default:
			break;
		}
	}

	bool UUIDObject::operator==(const UUIDObject& other) const
	{
		return uuid == other.uuid;
	}


	void UUIDObject::Finalize(const sobj& objptr)
	{
		objptr->HandleEvent(BEFORE_FINALIZED);
		objptr->self = nullptr;
	}
	bool operator==(const sobj& l, const sobj& r)
	{
		return l->GetUUID() == r->GetUUID();
	}
	size_t UUIDObjectComparer::operator()(const UUIDObject& l, const UUIDObject& r) const
	{
		return l == r;
	}
	size_t UUIDObjectComparer::operator()(const sobj& l, const sobj& r) const
	{
		return *l == *r;
	}
}