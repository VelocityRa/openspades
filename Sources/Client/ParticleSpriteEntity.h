//
//  ParticleSpriteEntity.h
//  OpenSpades
//
//  Created by yvt on 7/21/13.
//  Copyright (c) 2013 yvt.jp. All rights reserved.
//

#pragma once

#include "ILocalEntity.h"
#include "../Core/Math.h"
#include "Client.h"
namespace spades {
	namespace client{
		class IImage;
		
		class ParticleSpriteEntity: public ILocalEntity {
		public:
			enum BlockHitAction {
				Delete,
				Ignore,
				BounceWeak
			};
		private:
			IRenderer *renderer;
			GameMap *map;
			
			IImage *image;
			Vector4 color;
			bool additive;
			BlockHitAction blockHitAction;
			
			Vector3 position, velocity; // unit/sec
			float radius, radiusVelocity; // unit/sec
			float angle, rotationVelocity; // radian/sec
			
			float velocityDamp;
			float radiusDamp;
			float gravityScale;
			
			float lifetime, time;
			float fadeInDuration;
			float fadeOutDuration;
		public:
			ParticleSpriteEntity(Client *cli, IImage *image, Vector4 color);
			
			virtual ~ParticleSpriteEntity(){}
			
			virtual bool Update(float dt);
			virtual void Render3D();
			
			void SetAdditive(bool b){additive = b;}
			
			void SetLifeTime(float lifeTime,
							 float fadeIn,
							 float fadeOut);
			
			void SetTrajectory(Vector3 initialPosition,
							   Vector3 initialVelocity,
							   float velocityDamp = 1.f,
							   float gravityScale = 1.f);
			
			void SetRotation(float initialAngle,
							 float angleVelocity = 0.f);
			
			void SetRadius(float initialRadius,
						   float radiusVelocity = 0.f,
						   float radiusDamp = 1.f);
			
			void SetBlockHitAction(BlockHitAction act){
				blockHitAction = act;
			}
			
			void SetImage(IImage *img) { image = img;}
			void SetColor(Vector4 col) { color = col;}
			
			IRenderer *GetRenderer() { return renderer; }
			
		};
	}
}