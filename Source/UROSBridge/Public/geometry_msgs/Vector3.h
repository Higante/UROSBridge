#pragma once

#include "ROSBridgeMsg.h"


namespace geometry_msgs
{
	class Vector3 : public FROSBridgeMsg
	{
		double X;
		double Y;
		double Z;
	public:
		Vector3()
		{
			MsgType = TEXT("geometry_msgs/Vector3");
		}
		
		Vector3(double InX,
			double InY,
			double InZ)
			:
			X(InX),
			Y(InY),
			Z(InZ)
		{
			MsgType = TEXT("geometry_msgs/Vector3");
		}

		// DEPRECATED! Will be removed when the generator is used again.
		Vector3(const FVector& InVector)
		{
			MsgType = "geometry_msgs/Vector3";
			X = InVector.X;
			Y = InVector.Y;
			Z = InVector.Z;
		}

		~Vector3() override {}

		// Getters 
		double GetX() const { return X; }
		double GetY() const { return Y; }
		double GetZ() const { return Z; }

		// DEPRECATED! Will be removed when the generator is used again.
		FVector GetVector() const
		{
			return FVector(X, Y, Z);
		}

		// Setters 
		void SetX(double InX) { X = InX; }
		void SetY(double InY) { Y = InY; }
		void SetZ(double InZ) { Z = InZ; }

		// DEPRECATED! Will be removed when the generator is used again.
		void SetVector(const FVector& InVector)
		{
			X = InVector.X;
			Y = InVector.Y;
			Z = InVector.Z;
		}

		virtual void FromJson(TSharedPtr<FJsonObject> JsonObject) override
		{
			X = JsonObject->GetNumberField(TEXT("x"));

			Y = JsonObject->GetNumberField(TEXT("y"));

			Z = JsonObject->GetNumberField(TEXT("z"));

		}

		virtual void FromBson(TSharedPtr<FBsonObject> BsonObject) override
		{
			X = BsonObject->GetNumberField(TEXT("x"));

			Y = BsonObject->GetNumberField(TEXT("y"));

			Z = BsonObject->GetNumberField(TEXT("z"));

		}

		static Vector3 GetFromJson(TSharedPtr<FJsonObject> JsonObject)
		{
			Vector3 Result;
			Result.FromJson(JsonObject);
			return Result;
		}

		static Vector3 GetFromBson(TSharedPtr<FBsonObject> BsonObject)
		{
			Vector3 Result;
			Result.FromBson(BsonObject);
			return Result;
		}

		virtual TSharedPtr<FJsonObject> ToJsonObject() const override
		{
			TSharedPtr<FJsonObject> Object = MakeShareable<FJsonObject>(new FJsonObject());

			Object->SetNumberField(TEXT("x"), X);

			Object->SetNumberField(TEXT("y"), Y);

			Object->SetNumberField(TEXT("z"), Z);

			return Object;

		}

		virtual TSharedPtr<FBsonObject> ToBsonObject() const override
		{
			TSharedPtr<FBsonObject> Object = MakeShareable<FBsonObject>(new FBsonObject());

			Object->SetNumberField(TEXT("x"), X);

			Object->SetNumberField(TEXT("y"), Y);

			Object->SetNumberField(TEXT("z"), Z);

			return Object;

		}

		virtual FString ToString() const override
		{
							
			return TEXT("Vector3 { x = ") + FString::SanitizeFloat(X) +
				TEXT(", y = ") + FString::SanitizeFloat(Y) +
				TEXT(", z = ") + FString::SanitizeFloat(Z) +
				TEXT(" } ");

		}


		virtual FString ToYamlString() const override
		{
			FString OutputString;
			TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
			FJsonSerializer::Serialize(ToJsonObject().ToSharedRef(), Writer);
			return OutputString;
		}
						
	};
	
}